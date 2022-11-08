class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = math.ceil(math.sqrt(c))
        while a >= 0:
            target = c - a ** 2
            cand = bisect.bisect_left(range(0, target+1), 1, key=lambda x: 1 if x ** 2 >= target else 0)
            if cand > a:
                break
            if cand ** 2 == target:
                return True
            a -= 1
        return False
