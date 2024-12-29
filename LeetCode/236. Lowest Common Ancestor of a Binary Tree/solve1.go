/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if p == q { return p; }

    var st, stp, stq []*TreeNode
    var traversal func(cur *TreeNode)
    traversal = func(cur *TreeNode) {
        if cur == nil { return }
        if stp == nil || stq == nil {
            st = append(st, cur)
            if cur == p { stp = make([]*TreeNode, len(st)); copy(stp, st); }
            if cur == q { stq = make([]*TreeNode, len(st)); copy(stq, st); }
            if cur.Left != nil  { traversal(cur.Left) }
            if cur.Right != nil { traversal(cur.Right) }
            st = st[:len(st)-1]
        }
    }
    traversal(root)
    ancestor := root
    for i := 1; i < min(len(stp), len(stq)) && stp[i] == stq[i]; i++ {
        ancestor = stp[i];
	}
    return ancestor
}
