class Solution {
  List<double> calcEquation(List<List<String>> equations, List<double> values, List<List<String>> queries) {
    List<String> symbols = [];
    List<List<int>> adjs = [];
    List<List<double>> weights = [];
    int symbolId(String s) => symbols.indexWhere((v) => v == s);


    for (int i = 0; i < equations.length; ++i) {
        final [to, from] = equations[i];
        final value = values[i];
        if (!symbols.contains(to)) symbols.add(to);
        if (!symbols.contains(from)) symbols.add(from);
        while (adjs.length < symbols.length) adjs.add([]);
        while (weights.length < symbols.length) weights.add([]);
        adjs[symbolId(from)].add(symbolId(to));
        weights[symbolId(from)].add(value);
        adjs[symbolId(to)].add(symbolId(from));
        weights[symbolId(to)].add(1/value);
    }

    List<double> res = [];
    for (final [to, from] in queries) {
        Map<int, double> visited = {};
        final fromId = symbolId(from), toId = symbolId(to);
        if (fromId == -1 || toId == -1) { res.add(-1); continue; }
        if (fromId == toId) { res.add(1); continue; }
        visited[fromId] = 1;
        List<int> q = [fromId], qNext = [];
        double found = -1;
        whileLoop:
        while (!q.isEmpty) {
            for (final a in q) {
                for (int i = 0; i < adjs[a].length; ++i) {
                    final b = adjs[a][i];
                    if (!visited.containsKey(b)) {
                        double updatedWeight = visited[a]! * weights[a][i];
                        visited[b] = updatedWeight;
                        if (b == toId) {
                            found = updatedWeight;
                            break whileLoop;
                        }
                        qNext.add(b);
                    }
                }
            }
            q = qNext; qNext = [];
        }
        res.add(found);
    }
    return res;
  }
}
