class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
       for i in stride(from: m+n-1, to: m+n-1-m, by: -1) {
           nums1[i] = nums1[i-n]
       }
        var p1 = n
        var i = 0
        var p2 = 0
        while i < p1 {
            if (p1 < m+n && (p2 >= n || nums1[p1] <= nums2[p2])) {
                nums1[i] = nums1[p1]
                p1 += 1
            } else {
                nums1[i] = nums2[p2]
                p2 += 1
            }
            i += 1
        }
    }
}