class Solution {
    func isPowerOfTwo(_ n: Int) -> Bool {
        return n > 0 && (n-1) & n == 0
    }
}