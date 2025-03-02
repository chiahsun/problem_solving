import 'dart:collection';

class Solution {
  List<List<int>> mergeArrays(List<List<int>> nums1, List<List<int>> nums2) {
    final M = nums1.length, N = nums2.length, maxVal = max(nums1.last[0], nums2.last[0]);
    List<List<int>> L = [];
    for (int i = 0, k = 0; i < M || k < N;) {
        int minVal = maxVal, total = 0;
        if (i < M) minVal = min(minVal, nums1[i][0]);
        if (k < N) minVal = min(minVal, nums2[k][0]);
        if (i < M && nums1[i][0] == minVal) { total += nums1[i][1]; ++i; }
        if (k < N && nums2[k][0] == minVal) { total += nums2[k][1]; ++k; }
        L.add([minVal, total]);
    }
    return L;
  }
}
