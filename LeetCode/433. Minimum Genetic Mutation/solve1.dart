class Solution {
  bool oneDistance(String a, String b) {
    int cnt = 0;
    for (int i = 0; i < a.length; ++i) {
        if (a[i] != b[i]) ++cnt;
        if (cnt > 1) return false;
    }
    return cnt == 1;
  }

  int minMutation(String startGene, String endGene, List<String> bank) {
    if (startGene == endGene) return 0;
    if (!bank.contains(endGene)) return -1;
    List<String> q = [startGene], qNext = [];
    final visited = Set<String>();
    visited.add(startGene);
    int step = 0;
    while (!q.isEmpty) {
        ++step;
        for (final s in q) {
           for (final ba in bank) {
            if (!visited.contains(ba)) {
                if (oneDistance(s, ba)) {
                    visited.add(ba);
                    qNext.add(ba);
                    if (ba == endGene) return step;
                }
            }
           }
        }
        q = qNext; qNext = [];
    }
    return -1;
  }
}
