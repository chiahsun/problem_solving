/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? partition(ListNode? head, int x) {
    final dummyHead = ListNode(0, head);
    ListNode p1 = dummyHead;
    while (true) {
        final nxt = p1.next;
        if (nxt == null || nxt.val >= x) break;
        final ListNode theNext = nxt;
        p1 = theNext;
    }
    if (p1.next == null) return dummyHead.next;
    ListNode p2 = p1.next!;
    outerLoop:
    while (true) {
        while (true) {
            final nxt = p2.next;
            if (nxt == null || nxt.val < x) {
                if (nxt == null) break outerLoop;
                else             break;
            }
            final ListNode theNext = nxt;
            p2 = theNext;
        }
        while (p2.next != null && (p2.next!).val < x) {
            ListNode nxt = p2.next!;
            ListNode? oldNxtNxt = nxt.next;
            ListNode oldP1Next = p1.next!;
            p1.next = nxt; p1 = nxt; p1.next = oldP1Next;
            p2.next = oldNxtNxt;
        }
        if (p2.next == null) break;
        p2 = p2.next!;
    }
    return dummyHead.next;
  }
}
