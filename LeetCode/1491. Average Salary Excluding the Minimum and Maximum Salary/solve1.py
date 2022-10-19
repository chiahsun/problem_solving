class Solution:
    def average(self, salary: List[int]) -> float:
        maxv, minv, total = salary[0], salary[0], 0
        for s in salary:
            total += s
            maxv = max(maxv, s)
            minv = min(minv, s)
        return (total - maxv - minv) / (len(salary) - 2)

