class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.N = len(nums)
        self.mp = list(range(self.N))

    def reset(self) -> List[int]:
        self.mp = list(range(self.N))
        return map(lambda i: self.nums[i], self.mp)

    def shuffle(self) -> List[int]:
        for i in range(self.N):
            pos = randint(0, i)
            self.mp[pos], self.mp[i] = self.mp[i], self.mp[pos]
        return map(lambda i: self.nums[i], self.mp)
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
