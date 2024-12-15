class Solution {
    func swap(_ nums: inout [Int], _ i: Int, _ k: Int) {
        if i != k {
            nums[i] ^= nums[k]
            nums[k] ^= nums[i]
            nums[i] ^= nums[k]
        }
    }
    
    func swap(_ nums: inout [Int], _ r1: Range<Int>, _ r2: Range<Int>) {
        for i in r1 {
            let k = i - r1.startIndex + r2.startIndex
            swap(&nums, i, k)
        }
    }
    
    func rotateR(_ nums: inout [Int], _ r: Range<Int>, _ k :Int) {
        let N = r.endIndex - r.startIndex
        if N == 1 || k == 0 { return }
        if k > (N - k) {
            return rotateL(&nums, r, N-k)
        }
        swap(&nums, 
             r.startIndex..<(r.startIndex+k), 
             (r.endIndex-k)..<r.endIndex)
        rotateR(&nums, (r.startIndex+k)..<r.endIndex, k)
    }
    
    func rotateL(_ nums: inout [Int], _ r: Range<Int>, _ k :Int) {
        let N = r.endIndex - r.startIndex
        if N == 1 || k == 0 { return }
        if k > (N - k) {
            return rotateR(&nums, r, N-k)
        }
        swap(&nums, 
             r.startIndex..<(r.startIndex+k), 
             (r.endIndex-k)..<r.endIndex)
        rotateL(&nums, r.startIndex..<(r.endIndex-k), k)
    }
    
    func rotate(_ nums: inout [Int], _ k: Int) {
        let N = nums.count
        rotateR(&nums, 0..<N, k%N)
    }
}