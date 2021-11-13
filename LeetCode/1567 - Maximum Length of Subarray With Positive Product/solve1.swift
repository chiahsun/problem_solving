class Solution {
    func getMaxLen(_ nums: [Int]) -> Int {
        let N = nums.count
        var (pStart, nStart) = (N, N)
        var ans = 0
        
        for i in 0..<N {
            let x = nums[i]
            if x == 0 {
                (pStart, nStart) = (N, N)
            } else {
                if x > 0 {
                    pStart = min(i, pStart)
                } else {
                    (pStart, nStart) = (min(N, nStart), min(i, pStart))
                }
   
                // print("i: \(i) cur \(x) pos \(x > 0) pStart \(pStart) nStart \(nStart)")
                
                ans = max(ans, i-pStart+1)     
               
                // print(" ans: \(ans)")
            }
        }
        return ans
    }
}