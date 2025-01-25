enum Status { unknown, processing, safe, unsafe }

class Solution {
  List<int> eventualSafeNodes(List<List<int>> graph) {
    final N = graph.length;
    final status = List<Status>.filled(N, Status.unknown);
    void dfs(int x) {
        status[x] = Status.processing;
        for (final y in graph[x]) {
            if (status[y] == Status.unknown) dfs(y);
            if (status[y] == Status.unsafe || status[y] == Status.processing) {
                status[x] = Status.unsafe;
                break;
            }
        }
        if (status[x] == Status.processing) status[x] = Status.safe;
    }

    for (int i = 0; i < N; ++i) if (status[i] == Status.unknown) dfs(i);

    return Iterable<int>.generate(N).where((e) => status[e] == Status.safe).toList();
  }
}
