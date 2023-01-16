# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    leaf = 'f'

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        data = []
        def preorder_traversal(p):
            if not p:
                return
            data.append(str(p.val))
            if p.left:
                preorder_traversal(p.left)
            else:
                data.append(Codec.leaf)
            if p.right:
                preorder_traversal(p.right)
            else:
                data.append(Codec.leaf)
            
        preorder_traversal(root)
        data = ",".join(data)
        return data

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        it = iter(data.split(","))
        def preorder_traversal():
            cur = next(it)
            if cur == 'f':
                return None
            p = TreeNode(cur)
            p.left = preorder_traversal()
            p.right = preorder_traversal()
            return p
        return preorder_traversal() if data else None
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
