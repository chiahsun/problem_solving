class Solution {
  bool canFinish(int numCourses, List<List<int>> prerequisites) {
    final visited = List<int>.filled(numCourses, 0);
    final E = List.generate(numCourses, (i) => [], growable: true);
    for (final [a, b] in prerequisites) E[a].add(b);

    bool dfs(int a) {
        if (visited[a] == 2) return true;
        if (visited[a] == 1) return false;
        visited[a] = 1;
        for (final b in E[a]) if (!dfs(b)) return false;
        visited[a] = 2;
        return true;
    }
    for (int i = 0; i < numCourses; ++i)
        if (!dfs(i))
            return false;

    return true;
  }
}
