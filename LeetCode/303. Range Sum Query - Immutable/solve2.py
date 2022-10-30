class NumArray:

    def __init__(self, nums: List[int]):
        self.psum = [nums[0]]
        for i in range(1, len(nums)):
            self.psum.append(self.psum[-1] + nums[i])

    def sumRange(self, left: int, right: int) -> int:
        return self.psum[right] if left == 0 else self.psum[right] - self.psum[left-1]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
