class Solution {
    func subarraySum(_ nums: [Int], _ k: Int) -> Int {
        var ans = 0
        var total = 0
        var d: [Int: [Int]] = [:]
        for i in 0..<nums.count {
            total += nums[i]
            if total == k { ans += 1 }
            if let mapped = d[total - k] { ans += mapped.count }
            d[total, default: []].append(i)
        }
        return ans
    }
}