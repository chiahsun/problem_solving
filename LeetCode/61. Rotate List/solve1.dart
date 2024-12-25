/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? rotateRight(ListNode? head, int k) {
    if (head == null) return head;
    final ListNode theHead = head;
    int N = 1;
    for (var p = head; ; p = p.next!, ++N) {
        if (p.next == null) {
            k %= N;
            break;
        }
    }
    if (k == 0) return theHead;
    final dummyHead = ListNode(0, theHead);
    var p1 = dummyHead, p2 = theHead;
    for (int i = 0; i < N-k; ++i) {
        p1 = p1.next!; p2 = p2.next!;
    }
    final newHead = p2;
    p1.next = null;
    while (p2.next != null) p2 = p2.next!;
    p2.next = theHead;
    return newHead;
  }
}
