import 'dart:collection';

class Solution {
  List<List<int>> mergeArrays(List<List<int>> nums1, List<List<int>> nums2) {
    final M = nums1.length, N = nums2.length;
    List<List<int>> L = [];
    for (int i = 0, k = 0; i < M || k < N;) {
        if (k == N || (i < M && nums1[i][0] < nums2[k][0])) {
            L.add([nums1[i][0], nums1[i][1]]);
            ++i;
        } else if (i == M || (nums1[i][0] > nums2[k][0])) {
            L.add([nums2[k][0], nums2[k][1]]);
            ++k;
        } else {
            L.add([nums1[i][0], nums1[i][1] + nums2[k][1]]);
            ++i;
            ++k;
        }
    }
    return L;
  }
}
