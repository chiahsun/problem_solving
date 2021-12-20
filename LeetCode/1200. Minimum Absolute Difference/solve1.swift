class Solution {
    func minimumAbsDifference(_ arr: [Int]) -> [[Int]] {
        var arr = arr.sorted()
        var minDistance = Int.max
        var prev = arr[0]
        var ans: [[Int]] = []
        for i in 1..<arr.count {
            let curDistance = arr[i] - prev
            if curDistance <= minDistance {
                if curDistance < minDistance {
                    ans.removeAll()
                    minDistance = curDistance
                }
                ans.append([prev, arr[i]])
            }
            prev = arr[i]
        }
        return ans
    }
}