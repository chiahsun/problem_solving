/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? deleteDuplicates(ListNode? head) {
    if (head == null || head.next == null) return head;
    ListNode dummyHead = ListNode(0, head);
    ListNode p1 = dummyHead, p2 = head!;
    ListNode p3 = p2.next!;
    do {
        if (p2.val == p3.val) {
            while (p3.next != null && (p3.next!).val == p2.val) {
                p3 = p3.next!;
            }
            p1.next = p3.next;
        } else {
            p1 = p1.next!;
        }
        if (p1.next != null) p2 = p1.next!; else break;
        if (p2.next != null) p3 = p2.next!; else break;
    } while (true);
    return dummyHead.next;
  }
}
