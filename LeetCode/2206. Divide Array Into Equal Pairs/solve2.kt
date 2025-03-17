class Solution {
    fun divideArray(nums: IntArray): Boolean {
        val s: MutableSet<Int> = mutableSetOf()
        for (n in nums) {
            if (n !in s) {
                s.add(n)
            } else {
                s.remove(n)
            }
        }
        return s.isEmpty()
    }
}
