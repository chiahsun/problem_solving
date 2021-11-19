class Solution {
    func wiggleMaxLength(_ nums: [Int]) -> Int {
        var start = 0
        var A: [Int] = []
        while start < nums.count && A.count < 2 {
            let cur = nums[start]
            if A.isEmpty || A.last! != cur {
                A.append(cur)
            }
            start += 1
        }
        
        var incre = (A.count >= 2 ? A[1] > A[0] : true)
        
        for i in start..<nums.count {
            let cur = nums[i]
            var prev = A.last!
            if incre {
                if cur > prev { A[A.count-1] = cur }
                else if cur < prev { 
                    A.append(cur)
                    incre = false
                }
            } else {
                if cur < prev { A[A.count-1] = cur }
                else if cur > prev { 
                    A.append(cur)
                    incre = true
                }
            }
        }
        
        return A.count
    }
}