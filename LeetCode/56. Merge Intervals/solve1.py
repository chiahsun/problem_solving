class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def my_cmp(x, y):
            for i in range(2):
                if x[i] != y[i]:
                    return -1 if x[i] < y[i] else 1
            return 0

        intervals.sort(key=cmp_to_key(my_cmp))
        res = [intervals[0]]
        for cur in intervals:
            if res[-1][1] >= cur[0]:
                res[-1][1] = max(res[-1][1], cur[1])
            else:
                res.append(cur)
        return res
       
        return intervals
