class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        marks = [0] * numCourses
        to = [[] for _ in range(numCourses)]
        for pre in prerequisites:
            to[pre[1]].append(pre[0])
        res = []
        def visit(cur, res):
            if marks[cur] == 2:
                return True
            if marks[cur] == 1:
                return False
            marks[cur] = 1
            for t in to[cur]:
                if not visit(t, res):
                    return False
            marks[cur] = 2
            res.append(cur)
            return True
            
        for i in range(numCourses):
            if marks[i] == 0:
                if not visit(i, res):
                    return []
        return reversed(res)
