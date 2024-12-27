class Solution {
  List<int> findOrder(int numCourses, List<List<int>> prerequisites) {
    final visited = List<int>.filled(numCourses, 0), res = List<int>.filled(numCourses, 0);
    final E = List<List<int>>.generate(numCourses, (i) => [], growable: false);
    for (final [a, b] in prerequisites) E[a].add(b);
    int posCnt = 0;
    bool dfs(int a) {
        if (visited[a] == 2) return true;
        if (visited[a] == 1) return false;
        visited[a] = 1;
        for (final b in E[a]) if (!dfs(b)) return false;
        visited[a] = 2; res[posCnt++] = a;
        return true;
    }
    for (int i = 0; i < numCourses; ++i) if (!dfs(i)) return [];

    return res;
  }
}
