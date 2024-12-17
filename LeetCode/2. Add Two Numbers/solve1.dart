/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? addTwoNumbers(ListNode? l1, ListNode? l2) {
    int carry = 0;
    final dummyHead = ListNode();
    var p = dummyHead;
    while (l1 != null || l2 != null || carry > 0) {
        carry = carry + (l1 != null  ? l1.val : 0) + (l2 != null  ? l2.val : 0);
        p = p.next = ListNode(carry % 10);
        carry ~/= 10;
        l1 = l1?.next; l2 = l2?.next;
    }
    return dummyHead.next;
  }
}
