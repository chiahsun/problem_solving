/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    var V []int
    var p = head
    for i := 0; p != nil; i, p = i+1, p.Next {
        V = append(V, p.Val)
        p.Val = i
    }

    var N []*Node
    dummyHead := &Node{0, nil, nil}
    for i, p, pNew := 0, head, dummyHead ;p != nil; i, p = i+1, p.Next {
        pNew.Next = &Node{V[i], nil, nil}
        pNew = pNew.Next
        N = append(N, pNew)
    }

    for p, pNew := head, dummyHead.Next; p != nil; p, pNew = p.Next, pNew.Next {
        if p.Random == nil {
            pNew.Random = nil
        } else {
            pNew.Random = N[p.Random.Val]
        }
    }

    return dummyHead.Next
}
