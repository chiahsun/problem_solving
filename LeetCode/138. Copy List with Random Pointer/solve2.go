/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    m := make(map[*Node]*Node)
    dummyHead := &Node{0, nil, nil}
    for i, p, pNew := 0, head, dummyHead ;p != nil; i, p = i+1, p.Next {
        pNew.Next = &Node{p.Val, nil, nil}
        pNew = pNew.Next
        m[p] = pNew
    }

    for p, pNew := head, dummyHead.Next; p != nil; p, pNew = p.Next, pNew.Next {
        if p.Random == nil {
            pNew.Random = nil
        } else {
            pNew.Random = m[p.Random]
        }
    }

    return dummyHead.Next
}
