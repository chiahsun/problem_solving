class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        res = 0
        for cost in costs:
            if coins - cost >= 0:
                res += 1
                coins -= cost
            else:
                break
            if coins == 0:
                break
        return res
            
