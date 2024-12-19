class Solution {
  List<List<int>> threeSum(List<int> nums) {
    nums.sort();
    List<List<int>> res = [];
    final N = nums.length;
    // print('nums: $nums');
    for (int i = 0; i < N-2;) {
        int target = -nums[i];
        int lo = i+1, hi = N-1;
        while (lo < hi) {
            // print('i: $i > lo: $lo hi: $hi');
            if (nums[lo] + nums[hi] == target) {
                res.add([nums[i], nums[lo], nums[hi]]);
                final loVal = nums[lo], hiVal = nums[hi];
                while (lo < hi && nums[lo] == loVal) ++lo;
                // print('  >> lo: $lo hi: $hi');
            }
            if (nums[lo] + nums[hi] > target) --hi;
            else                              ++lo;
        }
        while (i < N && nums[i] == -target) ++i;
    }
    return res;
  }
}
