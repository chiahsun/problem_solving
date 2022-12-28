class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        N = len(rooms)
        visited, cnt = [False] * N, 0

        def dfs(x):
            nonlocal cnt
            visited[x] = True
            cnt += 1
            for r in rooms[x]:
                if not visited[r]:
                    dfs(r)
        dfs(0)
        return cnt == N
        
