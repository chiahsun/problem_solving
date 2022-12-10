class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        new_start, new_end = newInterval[0], newInterval[1]
        start_pos = bisect_left(intervals, new_start, key=lambda x: x[0])
        if start_pos >= 1 and intervals[start_pos-1][1] >= new_start:
            start_pos -= 1
            new_start = intervals[start_pos][0]
        end_pos = bisect_right(intervals, new_end, key=lambda x: x[1])
        if end_pos < len(intervals) and intervals[end_pos][0] <= new_end:
            new_end = intervals[end_pos][1]
            end_pos += 1
        return intervals[:start_pos]  + [[new_start, new_end]] + intervals[end_pos:]

