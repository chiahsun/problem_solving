class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        d = [gas[i] - cost[i] for i in range(len(gas))]
        if sum(d) < 0:
            return -1
        psum, start = -1, -1
        for i, a in enumerate(d):
            if psum < 0:
                if a >= 0:
                    psum = a
                    start = i
            else:
                psum += a
        return start
