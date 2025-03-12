class Solution {
    fun maximumCount(nums: IntArray): Int {
        var nNeg = 0; var nZero = 0;
        for (n in nums) {
            if (n < 0)       ++nNeg;
            else if (n == 0) ++nZero;
            else             break;
        }
        return max(nNeg, nums.size - nNeg - nZero);
    }
}
