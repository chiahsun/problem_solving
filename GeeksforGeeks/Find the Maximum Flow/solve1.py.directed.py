debug = False 
class FlowEdge:
    def __init__(self, the_from, to, capacity):
        self.the_from = the_from
        self.to = to
        self.capacity = capacity
        self.flow = 0
    def __repr__(self):
        #return f"({self.the_from} -> {self.to}    {self.flow}/{self.capacity})"
        return "({} -> {}    {}/{})".format(self.the_from, self.to, self.flow, self.capacity)
    def residualCap(self, cur): # cur node
        if cur == self.to:
            return self.flow
        else:
            return self.capacity - self.flow
    def addFlow(self, cur, val):
        if cur == self.the_from:
            self.flow += val
        else:
            self.flow -= val
    def other(self, cur):
        return self.to if cur == self.the_from else self.the_from

def hasAugmentingPath(NV, adjs):
    visited = [False] * NV

    bottle = 0x7FFFFFFF
    edges = []
    def dfs(cur, target):
        nonlocal bottle

        if cur == target:
            return True

        visited[cur] = True
        for e in adjs[cur]:
            other = e.other(cur)
            residualCap = e.residualCap(cur)
            if not visited[other] and residualCap > 0:
                if dfs(other, target):
                    bottle = min(bottle, residualCap)
                    edges.append([e, cur])
                    return True
        return False

    ret = dfs(0, NV-1)
    return [ret, list(reversed(edges)), bottle]

def updateFlow(edges, bottle):
    for [e, cur]  in edges:
        e.addFlow(cur, bottle)

T = int(input())
for _ in range(T):
    [NV, NE] = map(int, input().strip().split(" "))
    I = list(map(int, input().strip().split(" ")))
    E = []
    
    for i in range(0, 3*NE, 3):
        E.append(FlowEdge(I[i]-1, I[i+1]-1, I[i+2]))

    adjs = [list() for _ in range(NV)] 
    for e in E:
        adjs[e.the_from].append(e)
        adjs[e.to].append(e)
    maxflow = 0
    while True:
        [ret, edges, bottle] = hasAugmentingPath(NV, adjs)
        if debug:
            print('Find path:', [ret, edges, bottle])
        if not ret:
            break

        updateFlow(edges, bottle)
        if debug:
            print('After update:', adjs)
        maxflow += bottle
    print(maxflow)

