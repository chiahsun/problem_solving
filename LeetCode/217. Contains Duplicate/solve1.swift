class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        let x = nums.sorted()
        
        for i in 0..<x.count-1 {
            if x[i] == x[i+1] {
                return true
            }
        }
        return false
    }
}