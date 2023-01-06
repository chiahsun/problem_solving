class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        
        def counting_sort(costs):
            R = 100000 + 2 # 0 and right shift 1 buffer
            cnt = [0] * R
            for c in costs:
                cnt[c+1] += 1
            for i in range(1, R):
                cnt[i] += cnt[i-1]
            aux = costs[:]
            for c in aux:
                costs[cnt[c]] = c
                cnt[c] += 1
        
        acc, res = 0, 0
        counting_sort(costs)
        for c in costs:
            if acc + c > coins:
                break
            res += 1
            acc += c
        return res
