// 0,1,1,1,0,0
// 1 0 0
//   1 1 0
//       1 1 1

// 0 1 1 1
// 1 0 0
//.  1 1 -
class Solution {
    fun minOperations(nums: IntArray): Int {
        val N = nums.size
        var nFlip = 0
        for (i in 0..N-3) {
            if (nums[i] == 0) {
                ++nFlip
                for (k in i..i+2) {
                    nums[k] = 1 - nums[k]
                }
            }
        }
        return if ((nums[N-1] == 1) and (nums[N-2] == 1)) nFlip else -1
    }
}
