class Solution {
    func longestConsecutive(_ nums: [Int]) -> Int {
        var s = Set(nums)
        var ans = 0
        for a in nums where s.contains(a) {
            var i = a-1
            var k = a+1
            while true {
                if s.contains(i) { s.remove(i); i -= 1 }
                else if s.contains(k) { s.remove(k); k += 1 }
                else { break }
            }    
            ans = max(ans, k-i-1)
        }
        return ans
    }
}