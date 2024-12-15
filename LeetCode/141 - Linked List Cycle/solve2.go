// https://stackoverflow.com/questions/19979178/what-is-the-idiomatic-go-equivalent-of-cs-ternary-operator
func If[T any](cond bool, vtrue, vfalse T) T {
    if cond {
        return vtrue
    }
    return vfalse
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    p1, p2 := head, head
    for {
        p1 = If(p1 != nil, p1.Next, p1)
        p2 = If(p2 != nil && p2.Next !=nil, p2.Next.Next, nil)
        if (p2 == nil) || (p1 == p2) {
            break
        }
    }
    return p2 != nil;
}
