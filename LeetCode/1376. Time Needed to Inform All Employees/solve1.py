class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        subs = [[] for _ in range(len(manager))]
        for i in range(len(manager)):
            if manager[i] != -1:
                subs[manager[i]].append(i)
        def get_max_time(id):
            max_time = 0
            for sub in subs[id]:
                max_time = max(max_time, informTime[id] + get_max_time(sub))
            return max_time
        return get_max_time(headID)
