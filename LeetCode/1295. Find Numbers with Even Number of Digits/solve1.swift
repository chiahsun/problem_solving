class Solution {
    func findNumbers(_ nums: [Int]) -> Int {
        return nums.filter { a in
            var res = 1
            var b = a
            while b >= 10 {
                b /= 10
                res += 1
            }
            return res % 2 == 0
        }.count
    }
}