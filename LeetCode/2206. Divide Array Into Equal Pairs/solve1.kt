class Solution {
    fun divideArray(nums: IntArray): Boolean {
        val m: MutableMap<Int, Int> = mutableMapOf()
        for (n in nums) {
            if (n !in m || m[n] == 0) {
                m[n] = 1;
            } else {
                m[n] = 0;
            }
        }
        return m.all { (key, value) -> value == 0 }
    }
}
