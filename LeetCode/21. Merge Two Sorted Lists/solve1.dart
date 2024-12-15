/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? mergeTwoLists(ListNode? list1, ListNode? list2) {
    ListNode dummyHead = ListNode(0, null);
    ListNode p = dummyHead;
    while (list1 != null || list2 != null) {
        if (list2 == null || (list1 != null && list1.val <= list2.val)) {
            p.next = ListNode((list1?.val)!, null);
            list1 = list1?.next;
        } else {
            p.next = ListNode((list2?.val)!, null);
            list2 = list2?.next;
        }
        p = p.next!;
    }
    return dummyHead.next;
  }
}
