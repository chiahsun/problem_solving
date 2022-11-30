import queue
class Solution:
    # B A C B 
    # B A C B A C B D A B D

    def leastInterval(self, tasks: List[str], n: int) -> int:
        d = defaultdict(int)
        for t in tasks:
            d[t] += 1
        q = queue.PriorityQueue()
        for k, v in d.items():
            q.put((-v, k))
        cycle = 0
        while not q.empty():
            cnt1, t1 = q.get()
            cur = 1
            push_backs = [] 
            if cnt1 < -1:
                push_backs.append((cnt1+1, t1))
            for _ in range(n):
                if not q.empty():
                    cnt2, t2 = q.get()
                    cur += 1
                    if cnt2 < -1:
                        push_backs.append((cnt2+1, t2))
                else:
                    break
            for p in push_backs:
                q.put(p)
            if q.empty():
                cycle += cur
                break
            cycle += (n+1)
            
        return cycle

