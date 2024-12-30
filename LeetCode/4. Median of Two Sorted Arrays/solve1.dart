class Solution {
  double findMedianSortedArrays(List<int> nums1, List<int> nums2) {
    final M = nums1.length, N = nums2.length;
    final L = List<int>.filled(M+N, 0);
    int i = 0, k = 0, pos = 0;
    while (i < M || k < N) {
        if (k >= N || (i < M && nums1[i] <= nums2[k])) { L[pos++] = nums1[i++]; }
        else                                         { L[pos++] = nums2[k++]; } 
    }
    final cnt = (M+N);
    return cnt % 2 == 0 ? (L[cnt~/2-1] + L[cnt~/2]) / 2 : L[cnt~/2].toDouble();
  }
}
