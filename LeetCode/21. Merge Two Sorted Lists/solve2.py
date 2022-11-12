# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy, arr = ListNode(), [list1, list2]
        p = dummy
 
        def advance(arr, i):
            arr[i] = arr[i].next

        while all(arr):
            min_val = min(map(lambda x: x.val, arr))
            for i in range(len(arr)):
                if min_val == arr[i].val:
                    p.next = arr[i]; p = p.next; advance(arr, i)
                    break
        # https://stackoverflow.com/questions/18533620/getting-the-first-non-none-value-from-list
        try: 
            p.next = next(q for q in arr if q)
        except StopIteration:
            pass
        
        return dummy.next
