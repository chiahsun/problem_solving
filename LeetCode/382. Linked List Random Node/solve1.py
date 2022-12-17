# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head
        N, p = 0, head
        while p:
            N += 1
            p = p.next
        self.N = N
        

    def getRandom(self) -> int:
        cnt, p = self.N, self.head
        while p and cnt > 1:
            if randint(0, cnt-1) == 0:
                break
            cnt -= 1
            p = p.next
        return p.val
        

        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
