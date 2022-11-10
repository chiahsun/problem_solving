class Solution {
    func runningSum(_ nums: [Int]) -> [Int] {
        var ans: [Int] = []
        
        // https://developer.apple.com/documentation/swift/array/2298686-reduce
        nums.reduce(0, { acc, elem in
            let now = acc + elem
            ans.append(now)
            return now
        })
        return ans
    }
}