# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        st, p = [root], root
        while p.left:
            p = p.left
            st.append(p)
        while st:
            if k == 1:
                return st[-1].val
            last = st.pop()
            k -= 1
            p = last
            if p.right:
                p = p.right
                st.append(p)
                while p.left:
                    p = p.left
                    st.append(p)
        return -1

