class Solution {
    // 1 1 1 2 8 8 2 1 1 1 
    // 1 x 9 = 9
    // 8 x 1 = 1
    // 2 x 3 = 6
    
    // 1 6 1 6 1 19 2
    // 1 x 6 = 6
    // 6 x 4 = 24
    
    // >= 1 left most 1 right most
    // >= 2 
    // >= 6
    // >= 19
    
    func maxArea(_ height: [Int]) -> Int {
        var (i, k) = (0, height.count-1)
        var ans = 0
        while i < k {
            let (lh, rh) = (height[i], height[k])
            ans = max(ans, (k-i) * min(lh, rh))
            
            if lh <= rh { i += 1 }
            else        { k -= 1 }
        }
        return ans
    }
}