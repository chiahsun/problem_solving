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
        if (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                p.next = list1;
                list1 = list1.next;
            } else {
                p.next = list2;
                list2 = list2.next;
            }
            p = p.next!;
        } else {
            p.next = (list1 == null) ? list2 : list1;
            break;
        }
    }
    return dummyHead.next;
  }
}
