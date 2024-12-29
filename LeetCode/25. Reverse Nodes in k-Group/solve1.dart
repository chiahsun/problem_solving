/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  void reverseList(ListNode p1, ListNode p2) {
    final nextHead = p2.next;
    ListNode p = p1.next!;
    ListNode? pTail = nextHead;
    while (true) {
        final pn = p.next;
        p.next = pTail;
        pTail = p;
        if (pn == nextHead || pn == null) break;
        p = pn;
    }
    p1.next = p;
  }

  ListNode? reverseKGroup(ListNode? head, int k) {
    if (head == null || k == 1) return head;
    final theHead = head;
    final dummyHead = ListNode(0, theHead);
    ListNode p1 = dummyHead;
    ListNode? p2 = dummyHead;
    while (true) {
        for (int i = 0; i < k; ++i) p2 = p2?.next;
        if (p2 == null) return dummyHead.next;
        final newTail = p1.next!;
        reverseList(p1, p2);
        p1 = p2 = newTail;
    }
    return dummyHead.next;
  }
}
