class Solution {
    
    func gcd(_ a: Int, _ b: Int) -> Int {
        var a = a
        var b = b
        while b > 0 {
            (a, b) = (b, a%b)
        }
        return a
    }
    
    func substitute(_ nums: inout [Int], _ k: Int, _ start: Int) {
        var i = start
        var tofill = nums[i]
        repeat {
            let next = (i + k) % nums.count
            
            let tmp = nums[next]
            nums[next] = tofill
            tofill = tmp
            
            i = next
        } while i != start
    }
    
    func rotate(_ nums: inout [Int], _ k: Int) {
        var k = k % nums.count
        if k == 0 { 
            return 
        }
        
        let count = gcd(nums.count, k)
        // print("count \(count)")
        for i in 0..<count {
            substitute(&nums, k, i)
        }
    }
}