// 1010
// 0010
// 0101
// 1101 8+4+1=13

class Solution {
  int xorAllNums(List<int> nums1, List<int> nums2) {
    int xorReduce(List<int> nums1) => nums1.reduce((accu, elem) => accu ^ elem);
    final M = nums1.length, N = nums2.length;
    return (N % 2 == 1 ? xorReduce(nums1) : 0) ^ (M % 2 == 1 ? xorReduce(nums2): 0);
  }
}
