/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode? next;
 *   ListNode([this.val = 0, this.next]);
 * }
 */
class Solution {
  ListNode? mergeKLists(List<ListNode?> lists) {
    ListNode? merge(ListNode? p1, ListNode? p2) {
      ListNode dummyHead = ListNode(0, null);
      ListNode p = dummyHead;
      while (p1 != null || p2 != null) {
        if (p1 == null) { p.next = p2; break; }
        if (p2 == null) { p.next = p1; break; }
        if (p1.val <= p2.val) {
            p = p.next = p1;
            p1 = p1.next;
        } else {
            p = p.next = p2;
            p2 = p2.next;
        }
      }
      return dummyHead.next;
    }

    ListNode? divide(List<ListNode?> L) {
        if (L.isEmpty) return null;
        if (L.length == 1) return L.first;
        ListNode? l1 = L[0], l2 = L[1];
        if (L.length > 2) {
            int N = (L.length+1) ~/ 2;
            l1 = divide(L.sublist(0, N));
            l2 = divide(L.sublist(N));
        }
        return merge(l1, l2);
    }

    return divide(lists);
  }
}
