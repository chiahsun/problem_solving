# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode()
        # https://stackoverflow.com/questions/8991840/recursion-using-yield
        def gen_list(p, done=False):
            if p.next:
                yield from gen_list(p.next)
            yield p.val
            while done:
                yield -1
        carry = 0
        p, gen1, gen2 = None, gen_list(l1, True), gen_list(l2, True)
        while True:
            a, b = next(gen1), next(gen2)
            if a == -1 and b == -1 and carry == 0:
                break
            carry += (a if a >= 0 else 0)
            carry += (b if b >= 0 else 0)
            p = ListNode(val=carry%10, next=p)
            carry //= 10
        return p
