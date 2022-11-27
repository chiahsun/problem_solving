# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        A, p = [], head
        while p:
            A.append(p.val)
            p = p.next
        N = len(A)
        return all(A[i] == A[N-i-1] for i in range(N // 2))
        
