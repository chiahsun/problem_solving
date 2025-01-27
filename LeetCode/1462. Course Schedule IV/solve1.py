# https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        D = [[-1] * numCourses for _ in range(numCourses)]
        for i in range(numCourses):
            D[i][i] = 0
        for [a, b] in prerequisites:
            D[a][b] = 1

        for n in range(numCourses):
            for i in range(numCourses):
                for k in range(numCourses):
                    if D[i][n] >= 0 and D[n][k] >= 0 and (D[i][k] == -1 or D[i][k] < D[i][n] + D[n][k]):
                        D[i][k] = D[i][n] + D[n][k]

        return [D[a][b] >= 0 for [a, b] in queries]
