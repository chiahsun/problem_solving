class Solution {
    func count(_ piles: [Int], _ val: Int) -> Int {
        piles.reduce(0, { acc, cur in
            acc + (cur+val-1)/val      
        })
    }
    
    func minEatingSpeed(_ piles: [Int], _ h: Int) -> Int {
        var i = 1, k = piles.max()!
        while i < k {
            let mid = (i+k)/2
            let used = count(piles, mid)
            // print("mid: \(mid) used: \(used)")
            if used > h { i = mid+1 }
            else        { k = mid }
        }
        return i
    }
}