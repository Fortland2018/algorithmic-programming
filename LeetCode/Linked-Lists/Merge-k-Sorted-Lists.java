1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode() {}
7 *     ListNode(int val) { this.val = val; }
8 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11class Solution {
12    public ListNode mergeKLists(ListNode[] lists) {
13
14        if (lists.length == 0)
15            return null;
16
17        Queue<ListNode> q = new PriorityQueue<>((a, b) -> a.val - b.val);
18        for (ListNode k : lists) {
19            if (k != null)
20                q.offer(k);
21        }
22
23        ListNode head = new ListNode();
24        boolean first = false;
25        ListNode b = new ListNode();
26        
27        head.next = b;
28        
29
30        while (!q.isEmpty()) {
31            ListNode tail = q.poll();
32            if (tail != null) {
33                b.next = tail;
34                if(tail.next != null) q.offer(tail.next);
35                
36                b = tail;
37            
38            }
39
40        }
41
42        return head.next.next;
43    }
44}
45
46
47
48
49
50
51