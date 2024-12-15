class Solution {
  int removeElement(List<int> nums, int val) {
    int k = 0;
    for (final n in nums) {
        if (n != val) nums[k++] = n;
    }
    return k;
  }
}
