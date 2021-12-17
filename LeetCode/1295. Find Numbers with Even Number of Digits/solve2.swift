class Solution {
    func findNumbers(_ nums: [Int]) -> Int {
        nums.reduce(0, { acc, elem in
            var a = elem
            var nDigits = 1
            while a >= 10 {
                a /= 10
                nDigits += 1
            }
            return nDigits % 2 == 0 ? (acc+1) : acc
        })
    }
}