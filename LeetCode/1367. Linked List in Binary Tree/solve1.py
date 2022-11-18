# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        ll, p = [], head
        while p:
            ll.append(p.val)
            p = p.next

        def traverse(prev, p) -> bool:
            N, pop_idx = len(prev), 0
            # Maybe some problem here ...
            for i in range(N):
                if prev[i] != -1 and ll[N-i] == p.val:
                    break
                else:
                    pop_idx = i+1
            prev = prev[pop_idx:]
            if ll[0] == p.val:
                prev.append(p.val)
            elif len(prev) > 0:
                prev.append(-1)
            return len(prev) == len(ll) or (p.left and traverse(prev[:], p.left)) or (p.right and traverse(prev[:], p.right))

        return traverse([], root)
        
