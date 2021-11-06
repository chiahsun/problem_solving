class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        let x = nums.sorted()
        for i in stride(from: 0, to: x.count-1, by: 3) {
            if (x[i] == x[i+1] && x[i+1] == x[i+2]) {
            } else {
                return x[i] ^ x[i+1] ^ x[i+2]
            }
        }
        return x.last!
    }
}