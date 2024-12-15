class Solution {
  int removeDuplicates(List<int> nums) {
    int i = 0;
    for (int k = 1; k < nums.length; ++k) {
        if (nums[k] != nums[i])
            nums[++i] = nums[k];
    }
    return i+1;
  }
}
