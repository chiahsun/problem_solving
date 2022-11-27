# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        def traverse_and_remove(prev, cur):
            cnt = 1 if not cur.next else traverse_and_remove(cur, cur.next)
            if cnt == n:
                prev.next = cur.next
            return 1 + cnt
        dummyHead = ListNode(next=head)
        traverse_and_remove(dummyHead, head)
        return dummyHead.next
