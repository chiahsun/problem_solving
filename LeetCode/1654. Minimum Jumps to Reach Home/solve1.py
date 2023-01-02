class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        # If a >= b, we start from 0 since a-b >= cur position and
        # if a-b > target we won't never back 
        # since we can only jump backward once in a row
        #
        # If b is larger, we start from x since
        # it is equivalent to jump b forward starting from x
        # but we can only jump forward once in a row
        if x == 0:
            return 0
        s, t = 0, x
        if a >= b:
            b = -b
        else:
            s, t = t, s
            a = -a
        # We can only do b once
        # Tricky part: we need to encode did_b in visited
        q, d, forbidden, visited = [(s, False)], 0, set(forbidden), {(s, False)}
        # Bound for search, see
        # https://leetcode.com/problems/minimum-jumps-to-reach-home/solutions/936440/java-python-3-bfs-clean-codes-w-brief-explanation-and-analysis/
        # https://leetcode.com/problems/minimum-jumps-to-reach-home/solutions/978357/c-bidirectional-bfs-solution-with-proof-for-search-upper-bound/ 
        bound = abs(a)+abs(b)+max(t, max(forbidden))
        while q:
            sz = len(q)
            for cur, did_b in q[:sz]:
                if cur+a == t:
                    return d+1
                candidates = []
                if s == 0: # s == 0, a >= b for original setting
                    assert a > 0
                    assert b < 0
                    assert a + b >= 0
                    if cur + a + b <= t and (cur + a <= bound):
                        candidates.append((cur+a, False))
                else: # s != 0, a < b for original setting
                    assert a < 0
                    assert b > 0
                    if cur+a >= 0 and (cur + a <= bound):
                        candidates.append((cur+a, False))
                
                if not did_b:
                    if cur+b == t:
                        return d+1
                    if cur+b >= 0:
                        candidates.append((cur+b, True))
                
                for cand in candidates:
                    n = cand[0]
                    if n not in forbidden and cand not in visited and (n-a*b <= 0 or n - a * b not in visited):
                        q.append(cand)
                        visited.add(cand)
            d += 1
            q = q[sz:]
        return -1
