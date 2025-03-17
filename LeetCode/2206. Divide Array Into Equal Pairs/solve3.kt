class Solution {
    fun divideArray(nums: IntArray): Boolean {
        val cnts = Array(500+1) { 0 }
        var nFail = 0
        for (n in nums) {
            if (cnts[n] == 0) { ++cnts[n]; ++nFail }
            else              { --cnts[n]; --nFail }
        }
        return nFail == 0
    }
}
