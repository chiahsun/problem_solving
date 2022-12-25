https://www.interviewbit.com/problems/cycle-in-undirected-graph/

https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

1. DFS, suppose v -> w, and there exist another edge/indirect edge that is different from current w -> v back edge. (Since the graph is undirected, when we trace v->w, there is always w->v, so we need to ignore direct w->v during traversal.

2. Use union-find for all edges, redundant edge creates a cycle.
