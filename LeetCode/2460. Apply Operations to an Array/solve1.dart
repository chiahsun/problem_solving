class Solution {
  List<int> applyOperations(List<int> nums) {
    final N = nums.length;
    int writePos = 0;
    for (int i = 0; i < N; ) {
        if (nums[i] == 0) {
            ++i;
        } else if (i < N-1 && nums[i] == nums[i+1]) {
            nums[writePos++] = nums[i] * 2;
            i += 2;
        } else {
            nums[writePos++] = nums[i];
            ++i;
        }
    }
    while (writePos < N) nums[writePos++] = 0;
    return nums;
  }
}
