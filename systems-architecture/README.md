# Systems Architecture

Problems and implementations related to low-level systems and computer architecture.

## Programs

| File | Description |
|------|-------------|
| `assembly_solution.s` | x86-64 assembly implementation of a **GShare branch predictor**: exposes `init`, `predict_branch`, and `actual_branch` routines that maintain a 4096-entry Pattern History Table (PHT) and a 12-bit Global History Register (GHR). |
| `driver.cpp` | C++ driver used to test the branch predictor alongside quicksort, prime sieve, and Caesar cipher utilities. |
