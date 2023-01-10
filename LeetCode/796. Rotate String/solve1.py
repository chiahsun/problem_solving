class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): 
            return False
        if sorted(s) != sorted(goal):
            return False
        N = len(s)
        for i in range(N):
            ok = True
            for k in range(N):
                if s[(i+k) % N] != goal[k]:
                    ok = False
                    break
            if ok:
                return True
        return False
