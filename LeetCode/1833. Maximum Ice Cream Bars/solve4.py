class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        # https://docs.python.org/zh-tw/3/library/collections.html
        counter, res = Counter(costs), 0
        for cost in sorted(counter.keys()):
            cnt = counter[cost]
            n = min(coins // cost, cnt)
            if n > 0:
                coins -= cost*n
                res += n
            if n == 0 or coins < cost:
                break

        return res
            
