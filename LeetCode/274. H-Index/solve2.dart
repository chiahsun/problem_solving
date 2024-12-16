class Solution {
  int hIndex(List<int> citations) {
    citations.sort();

    int start = 0, res = 0;
    for (int i = 0; i < citations.length; ++i) {
        int c = citations[i];
        if (c > res) ++res;
        while(start < i && citations[start] < res) {
            start++;
        }
        if (i - start + 1 < res) res--;
    }
    return res;
  }
}
