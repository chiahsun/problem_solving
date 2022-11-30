/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let p1 = l1, p2 = l2;
    let dummyHead = new ListNode(0, undefined);
    let p = dummyHead;
    let carry = 0;
    do {
        let sum = (p1 ? p1.val : 0) + (p2 ? p2.val : 0) + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        p.next = new ListNode(sum, undefined);
        p = p.next;
        p1 = (p1 ? p1.next : null);
        p2 = (p2 ? p2.next : null);
    } while (p1 || p2 || carry > 0);
    return dummyHead.next;
};