/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	var rights[] *Node

    var rightFirstDFS func(p *Node, depth int)
    rightFirstDFS = func(p *Node, depth int) {
        if len(rights) <= depth {
            p.Next = nil
            rights = append(rights, p)
        } else {
            p.Next = rights[depth]
            rights[depth] = p;
        }

        if p.Right != nil {
            rightFirstDFS(p.Right, depth+1)
        }
        if p.Left != nil {
            rightFirstDFS(p.Left, depth+1)
        }
    }

    if (root != nil) {
        rightFirstDFS(root, 0)
    }
    return root
}
