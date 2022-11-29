# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        from_head = head
        def reorder(p):
            nonlocal from_head
            if p.next:
                reorder(p.next)
            if not from_head:
                return
            
            if from_head.next == p:
                p.next = None
                from_head = None
            else:
                old_next = from_head.next
                from_head.next = p
                if old_next and old_next.next == from_head:
                    from_head.next = None
                    from_head = None
                else:
                    from_head = old_next
                    p.next = from_head
        reorder(head)
