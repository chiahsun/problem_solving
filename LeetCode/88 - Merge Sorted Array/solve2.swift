class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var p1 = m-1
        var p2 = n-1
        var i = m+n-1
        while i > p1 {
            if (p1 >= 0) && (p2 < 0 || nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1]
                p1 -= 1
            } else {
                nums1[i] = nums2[p2]
                p2 -= 1
            }
            i -= 1
        }
    }
}