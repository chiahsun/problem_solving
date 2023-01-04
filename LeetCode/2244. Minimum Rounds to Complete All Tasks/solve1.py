class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        d = defaultdict(int)
        for t in tasks:
            d[t] += 1
        res = 0
        for cnt in d.values():
            if cnt == 1:
                return -1
            res += ((cnt + 2) // 3)
        return res
