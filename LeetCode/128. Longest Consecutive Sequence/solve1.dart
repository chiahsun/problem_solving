class Solution {
  int longestConsecutive(List<int> nums) {
    var s = {...nums}, s2 = Set<int>();
    int res = 0;
    for (final n in nums) {
        if (!s2.contains(n)) {
            s2.add(n);
            int minVal = n, maxVal = n;
            while(s.contains(maxVal+1)) { ++maxVal; s2.add(maxVal); }
            while(s.contains(minVal-1)) { --minVal; s2.add(minVal); }
            res = max(res, maxVal - minVal + 1);
        }
    }
    return res;
  }
}
