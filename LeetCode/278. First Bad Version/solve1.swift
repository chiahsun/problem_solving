/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */

class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var lo = 1
        var hi = n
        
        while lo < hi {
            let mid = (lo + hi)/2
            let isBad = isBadVersion(mid)
            if isBad {
                hi = mid
            } else {
                lo = mid+1
            }
        }
        return lo
    }
}
