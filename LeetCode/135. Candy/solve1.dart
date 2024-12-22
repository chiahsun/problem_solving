class Solution {
  int candy(List<int> ratings) {
    if (ratings.length == 1) return 1;

    final N = ratings.length;
    final candies = List<int>.filled(N, -1);
    List<int> vallies = [];
    int? start = 0;
    for (int i = 1; i < N+1; ++i) {
        if (i == N) {
            if (start != null) {
                vallies.add(start);
                if (i-1 != start) vallies.add(i-1);
            }
        } else if (start == null) {
            if (ratings[i] <= ratings[i-1]) start = i;
        } else {
            if (ratings[i] > ratings[start]) {
                if (start != null) {
                    vallies.add(start);
                    if (i-1 != start) vallies.add(i-1);
                    start = null;
                }
            } else if (ratings[i] == ratings[start]) {

            } else {
                start = i;
            }
        }
    }
    for (final v in vallies) {
        candies[v] = 1;
        List<int> ds = [-1, 1];
        for (int d in ds) {
            int last = 1;
            for (int i = v + d; i >= 0 && i < N; i = i + d) {
                if (ratings[i] < ratings[i-d]) break;
                else if (ratings[i] == ratings[i-d]) {
                    if (candies[i] > 0) break;
                    else                last = candies[i] = 1;
                } else {
                    last = candies[i] = max(last+1, candies[i]);
                }
            }
        }
    }

    return candies.reduce((a, b) => a + b);
  }
}
