class Solution {
  List<int> findRedundantConnection(List<List<int>> edges) {
    final N = edges.length;
    List<List<int>> E = List.generate(N, (i) => [], growable: false);
    List<List<int>> EId = List.generate(N, (i) => [], growable: false);
    for (int i = 0; i < N; ++i) {
        final [a, b] = edges[i];
        E[a-1].add(b-1); EId[a-1].add(i);
        E[b-1].add(a-1); EId[b-1].add(i);
    }

    int detectCycle() {
        List<int> stNodes = [], stEdges = [];
        final visited = List<bool>.filled(N, false);
        int largestId = -1;

        void dfs(int cur, int eId) {
            if (visited[cur]) {
                largestId = eId;
                for (int i = stEdges.length-1; i >= 0; --i) {
                    if (stNodes[i] == cur) break;
                    largestId = max(largestId, stEdges[i]);
                }
                return;
            }
            stNodes.add(cur);
            stEdges.add(eId);
            visited[cur] = true;
            for (int i = 0; i < E[cur].length && largestId < 0; ++i) {
                int next = E[cur][i];
                int nextEId = EId[cur][i];
                if (nextEId == eId) continue;
                dfs(next, nextEId);
            }
            stNodes.removeLast();
            stEdges.removeLast();
        }

        dfs(0, -1);
        return largestId;
    }

    return edges[detectCycle()];
  }
}
