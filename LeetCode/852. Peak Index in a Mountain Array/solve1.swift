class Solution {
    func peakIndexInMountainArray(_ arr: [Int]) -> Int {
        var lo = 0
        var hi = arr.count-1
        // 0 1 2 3
        while lo+2 < hi {
            let l = lo + (hi-lo)/3
            let r = lo + (hi-lo)*2/3
            if arr[l] <= arr[r] { lo = l }
            else                { hi = r }
        }
        return (lo...hi).map{ ($0, arr[$0]) }.max(by: {$0.1 < $1.1 })!.0
    }
}