class Solution {
  int kthFactor(int n, int k) {
    List<int> others = [];
    for (int d=1; d*d<=n; ++d) {
        if (n % d == 0) {

            --k;
            if (k == 0)  return d;
            if (d*d < n) others.add(n ~/ d);
        }
    }
    return others.length-k >= 0 ? others[others.length-k] : -1;
  }
}
