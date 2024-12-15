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
    var p1 = If(head != nil, head.Next, head)
    var p2 = If(p1 != nil, p1.Next, p1)
    for (p2 != nil) && (p1 != p2) {
        p1 = If(p1 != nil, p1.Next, p1)
        p2 = If(p2 != nil && p2.Next !=nil, p2.Next.Next, nil)
    }
    return p2 != nil;
}
