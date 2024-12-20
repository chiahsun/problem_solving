/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? reverseBetween(ListNode? head, int left, int right) {
    final dummyHead = ListNode(0, head);
    ListNode p1 = dummyHead;
    for (int i = 1; i < left; ++i) p1 = p1.next!;
    ListNode leftOuterHead = p1;
    if (p1.next == null) return dummyHead.next;
    ListNode tail = p1.next!;
    p1 = tail;
    ListNode? p2 = p1.next;
    for (int i = left; i < right && p2 != null; ++i) {
        final next = p2.next;
        p2.next = p1;
        p1 = p2;
        p2 = next;
    }
    tail.next = p2;
    leftOuterHead.next = p1;

    return dummyHead.next;
  }
}
