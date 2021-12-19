class NumArray(object):
    bucket_size = 512
    
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums = nums
        self.table = []
        bucket_size = NumArray.bucket_size
        for i in range(len(nums)//bucket_size):
            self.table.append(sum(nums[i*bucket_size: i*bucket_size+bucket_size]))

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        bucket_size, nums, table = NumArray.bucket_size, self.nums, self.table
        
        if i == j:
            return nums[i]
        
        vsum = 0
        now = i
        
        while now <= j:
            if now % bucket_size != 0:
                for k in range(now, min(j+1, now-(now%bucket_size) + bucket_size)):
                    vsum += nums[k]
                now -= (now%bucket_size)
            else:
                if now+bucket_size-1 <= j:
                    vsum += table[now//bucket_size]
                else:
                    for k in range(now, j+1):
                        vsum += nums[k]
            
            now += bucket_size
            
        return vsum         
        


# Your NumArray object will be instantiated and called as such:
numArray = NumArray([1, 2, 3, 4, 5])
print(numArray.sumRange(0, 1))
print(numArray.sumRange(1, 2))
numArray = NumArray([1] * 999)
print(numArray.sumRange(0, 499))
print(numArray.sumRange(0, 500))
print(numArray.sumRange(0, 998))
