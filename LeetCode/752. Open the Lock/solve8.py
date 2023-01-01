import queue

class Solution:
    @staticmethod
    def distance(s1, s2):
        cnt = 0
        for i in range(4):
            a, b = int(s1[i]), int(s2[i])
            if a != b:
                d = abs(a - b)
                cnt += min(10-d, d)
        return cnt

    @staticmethod
    def turn_helper(s, pos, cnt=1):
        return s[:pos] + str((int(s[pos]) + cnt) % 10) + s[pos+1:]

    @staticmethod
    def turn_up(s, pos):
        return Solution.turn_helper(s, pos, 1)

    @staticmethod
    def turn_down(s, pos):
        return Solution.turn_helper(s, pos, -1)

    def openLock(self, deadends: List[str], target: str) -> int:
        deadends, start = set(deadends), "0000"
        if start in deadends:
            return -1
        q, S = queue.PriorityQueue(), {start}
        q.put((Solution.distance(start, target), 0, start))
        while not q.empty():
            priority, real_cnt, a = q.get()
            if a == target:
                return real_cnt
            
            nxt_cnt, nxts = real_cnt+1, []
            for i in range(4):
                nxts.append(Solution.turn_up(a, i))
                nxts.append(Solution.turn_down(a, i))
            for nxt in nxts:
                if nxt not in deadends and nxt not in S:
                    S.add(nxt)
                    q.put((Solution.distance(nxt, target)+real_cnt, nxt_cnt, nxt))
            
        return -1
