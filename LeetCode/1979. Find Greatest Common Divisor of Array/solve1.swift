class Solution {
    private func gcd(_ a: Int, _ b: Int) -> Int {
        var a = a
        var b = b
        while b > 0 {
            (a, b) = (b, a % b)
        }
        return a
    }
    
    func findGCD(_ nums: [Int]) -> Int {
        var minVal = nums[0]
        var maxVal = nums[0]
        nums.forEach { a in
            minVal = min(minVal, a)
            maxVal = max(maxVal, a)
        }
        return gcd(minVal, maxVal)
    }
}