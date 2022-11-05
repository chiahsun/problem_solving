class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            another = target - numbers[i]
            k = bisect.bisect_left(numbers, another, lo=i+1)
            if k < len(numbers) and numbers[k] == another:
                return [i+1, k+1]

        return []
