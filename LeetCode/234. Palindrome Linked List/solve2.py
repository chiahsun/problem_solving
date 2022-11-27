# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        from_head = head
        def traverse_and_compare(p) -> (bool, bool):
            nonlocal from_head
            if not p.next:
                ok = p.val == from_head.val
                from_head = from_head.next
                return False, ok
            done, ok = traverse_and_compare(p.next)
            if done:
                return True, ok
            if from_head == p or (from_head.next and from_head.next.next and from_head.next.next == p):
                return True, ok and p.val == from_head.val
            ok = p.val == from_head.val
            from_head = from_head.next
            if not ok:
                return True, False
            return False, True
        return traverse_and_compare(head)[1] if head else True
