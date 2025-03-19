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
        var a = 0
        var b = 0
        for (i in 0..N-3) {
            val cur = nums[i]
            if ((cur + a) % 2 == 0) {
                ++nFlip
                a = (b+1).also { b = 1 }
            } else {
                a = b.also { b = 0}
            }
        }
        if ((nums[N-2] + a) % 2 == 0) return -1;
        if ((nums[N-1] + b) % 2 == 0) return -1;
        return nFlip;
    }
}
