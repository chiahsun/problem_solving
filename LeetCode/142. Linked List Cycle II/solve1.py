# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # First iteration (num_edges = 6 - 3 = 3)
    # 3 ->      2 ->       0       -> -4 (3) 
    # 3 -> 2 -> 0 -> -4 -> 2  -> 0 -> -4 (6)
    # Second iteration (Ans: node with val 2)
    # 3  -> 2  
    # -4 -> 2
 
    # First iteration (num_edges = 4 - 2 = 2)
    # 1      -> 2      -> 1 (2)
    # 1 -> 2 -> 1 -> 2 -> 1 (4)
    # Second iteration (Ans: node with val 1)
    # 1
    # 1

    # First iteration (Ans: None)
    # 1 -> None
    # 1 -> None

    # The difference is the number of edges (num_edges)
    # Result would be num_edges - offset (mod num_edges)
    # Therefore, after we have done first iteration, we start from head, and that met location of the first iteration and both steps 1 until met again
    
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Uncomment show to see the log
        def log(slow, fast, show=False):
            if show:
                print(slow and slow.val, fast and fast.val)
        slow = head and head.next
        fast = slow and slow.next
        log(slow, fast)
        while fast and fast != slow:
            slow = slow.next
            fast = fast.next and fast.next.next
            log(slow, fast)
        slow, slow2 = fast, head
        log(slow, fast)
        while slow and slow != slow2:
            slow = slow.next
            slow2 = slow2.next
            log(slow, fast)
        return slow
