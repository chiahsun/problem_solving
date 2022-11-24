class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        def is_arithmetic(f: int, t: int) -> bool:
            A = nums[f:t+1]
            A.sort()
            d = A[1] - A[0]
            for i in range(1, len(A)):
                if A[i] - A[i-1] != d:
                    return False
            return True
        return [is_arithmetic(f, t) for f, t in zip(l, r)]
            
