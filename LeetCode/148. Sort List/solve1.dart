/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? sortList(ListNode? head) {
    if (head == null || head.next == null) return head;
    ListNode? p1 = head, p2 = head.next;
    while (p2?.next != null) {
        p1 = p1?.next!;
        p2 = p2?.next?.next;
    }
    if (p1 != null) { // It won't be null, just passing nullity checking
        // print(p1.val);
        p2 = p1.next;
        p1.next = null;
        p1 = head;
    }
    // print("${p1?.val} ${p2?.val}");
    p1 = sortList(p1);
    p2 = sortList(p2);

    final dummyHead = ListNode();
    var p = dummyHead;
    while (p1 != null && p2 != null) {
        if (p1.val <= p2.val) { p = p.next = p1; p1 = p1.next; }
        else                  { p = p.next = p2; p2 = p2.next; }
    }
    if (p1 != null) p.next = p1;
    if (p2 != null) p.next = p2;
    return dummyHead.next;
  }
}
