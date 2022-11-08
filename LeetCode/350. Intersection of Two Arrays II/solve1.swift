class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var d1: [Int: Int] = [:]
        
        for a in nums1 {
            // https://stackoverflow.com/questions/31899613/most-optimal-way-to-increment-or-initialize-an-int-in-a-swift-dictionary/31899763
            d1[a, default: 0] += 1
        }
        
        var ans: [Int] = []
        for b in nums2 {
            if let cnt = d1[b], cnt > 0 {
                d1[b]! -= 1
                ans.append(b)
            }
        }
        return ans
    }
}