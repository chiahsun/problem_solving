# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        def inorder_traversal(p):
            if p.left:
                yield from inorder_traversal(p.left)
            yield p.val
            if p.right:
                yield from inorder_traversal(p.right)

        self.gen = inorder_traversal(root)
        self.buf = None
        
    def next(self) -> int:
        cur = self.buf
        if cur is not None:
            self.buf = None
            return cur
        
        return next(self.gen)

    def hasNext(self) -> bool:
        if self.buf is not None:
            return True
        try:
            self.buf = next(self.gen)
            return True
        except:
            return False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
