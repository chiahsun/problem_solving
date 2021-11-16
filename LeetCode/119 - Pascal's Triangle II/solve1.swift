class Solution {
    func getRow(_ rowIndex: Int) -> [Int] {
        var ans = [1]
        for i in 0..<rowIndex {
            var next: [Int] = [1]
            for k in 1..<i+1 {
                next.append(ans[k-1] + ans[k])
            }
            next.append(1)
            ans = next
        }
        return ans
    }
}