/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? removeNthFromEnd(ListNode? head, int n) {
    ListNode dummyHead = ListNode(0, head);
    ListNode p1 = dummyHead, p2 = head!;
    ListNode? p3 = p2.next;
    for (int i = 1; i < n; ++i) p3 = p3?.next;
    while (p3 != null) {
        (p1, p2, p3) = (p1.next!, p2.next!, p3?.next);
    }
    p1.next = p2.next;

    return dummyHead.next;
  }
}
