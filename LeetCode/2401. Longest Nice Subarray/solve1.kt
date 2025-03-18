// 1  3    8     48   10
// 1 11 1000 110000 1010

class Solution {
    fun longestNiceSubarray(nums: IntArray): Int {
        var begin = 0; var accu = nums[0]; var res = 1
        for (i in 1..<nums.size) {
            val cur = nums[i]
            while (begin < i && ((accu and cur) > 0)) {
                accu = accu and nums[begin].inv()
                ++begin
            }
            accu = accu or cur
            res = max(res, i - begin + 1)
        }
        return res
    }
}
