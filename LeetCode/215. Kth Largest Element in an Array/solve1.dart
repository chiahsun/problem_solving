class Solution {
  int findKthLargest(List<int> nums, int k) {
    return (nums..sort((a, b) => -a.compareTo(b)))[k-1];
  }
}
