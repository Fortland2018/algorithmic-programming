    .data
    .align 64
GSHARE_BHT_SIZE = 4096
GSHARE_BHT_MASK = GSHARE_BHT_SIZE - 1
    .comm GSHARE_BHT, GSHARE_BHT_SIZE, 64     # PHT: 4096 bytes, 2 bits per entry
    .comm GSHARE_GHR, 4, 4                    # Global History Register (32 bits; use lower 12)

    .text
    .global predict_branch
    .global actual_branch
    .global init

# set BHT(table) to 01 (weakly not-taken); zero hisotry
init:
    pushq   %rbp
    movq    %rsp, %rbp

    #%RBX, %RSP, %RBP, and %R12 through %R15. 

    leaq    GSHARE_BHT(%rip), %rdi
    movl    $GSHARE_BHT_SIZE, %ecx
    movl    $1, %eax
.init_loop:
    movb    %al, (%rdi)
    incq    %rdi
    decl    %ecx
    cmpl    $0, %ecx
    jne     .init_loop

    leaq    GSHARE_GHR(%rip), %rdi
    movl    $0, (%rdi)         # Zero global history

    movq    %rbp, %rsp
    popq    %rbp
    ret

# --- predict_branch(void* pc): RDI = IP, returns in RAX 1=Taken, 0=Not-Taken ---
predict_branch:
    pushq   %rbp
    movq    %rsp, %rbp

    # index = ((IP ) & 0xFFF) XOR (GHR & 0xFFF)
    movq    %rdi, %rax
    #shrq    $2, %rax
    andl    $GSHARE_BHT_MASK, %eax

    leaq    GSHARE_GHR(%rip), %rdx
    movl    (%rdx), %ecx
    andl    $GSHARE_BHT_MASK, %ecx

    xorl    %ecx, %eax            # EAX = index

    leaq    GSHARE_BHT(%rip), %rdx
    movzbl  (%rdx, %rax, 1), %ecx
    cmpl    $2, %ecx
    setge   %al
    movzbq  %al, %rax

    movq    %rbp, %rsp
    popq    %rbp
    ret

# --- actual_branch(void* pc, int taken): RDI = IP, RSI = outcome (0/1) ---
actual_branch:
    pushq   %rbp
    movq    %rsp, %rbp

    # Index = ((IP >> 2) & 0xFFF) XOR (GHR & 0xFFF)
    movq    %rdi, %rax
    
    andl    $GSHARE_BHT_MASK, %eax # IP

    leaq    GSHARE_GHR(%rip), %rdx # history
    movl    (%rdx), %ecx
    andl    $GSHARE_BHT_MASK, %ecx

    xorl    %ecx, %eax            # EAX = index

    leaq    GSHARE_BHT(%rip), %rdx
    movzbl  (%rdx, %rax, 1), %ecx  # rcx - index

    testl   %esi, %esi # esi & esi , if 0 then good, otherwise false
    je      .not_taken_gs
.taken_gs:
    cmpl    $3, %ecx
    je      .store_gs # if 2-bit pred is "11"
    incl    %ecx
    jmp     .store_gs
.not_taken_gs:
    testl   %ecx, %ecx
    je      .store_gs
    decl    %ecx
.store_gs:
    movb    %cl, (%rdx, %rax, 1) # update the table

    # Update global history: shift left, or in 'taken' (1/0), mask to 12 bits
    leaq    GSHARE_GHR(%rip), %rdx
    movl    (%rdx), %eax
    shll    $1, %eax
    andl    $GSHARE_BHT_MASK, %eax # mask
    orl     %esi, %eax # add 0 or 1 to eax
    movl    %eax, (%rdx) # save/updates the history

    movq    %rbp, %rsp
    popq    %rbp
    ret
