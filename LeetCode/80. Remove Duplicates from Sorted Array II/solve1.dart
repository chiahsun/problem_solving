class Solution {
  int removeDuplicates(List<int> nums) {
    int pos = 1, res = nums.length;
    for (int i = 2; i < nums.length; ++i) {
        int n = nums[i];
        if (n != nums[pos] || nums[pos] != nums[pos-1]) {
            nums[++pos] = n;
        } else {
            res--;
        }
    }
    return res;
  }
}
