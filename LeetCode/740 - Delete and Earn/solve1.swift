class Solution {
    func deleteAndEarn(_ nums: [Int]) -> Int {
        var d: [Int: Int] = [:]
        for x in nums {
            d[x, default: 0] += 1
        }
        // https://stackoverflow.com/questions/30969688/ordered-map-in-swift
        var ary = d.map { ($0, $1) }
        if ary.count == 1 {
            return ary[0].0 * ary[0].1
        }
        
        ary.sort() { $0.0 < $1.0 }
        var a1 = ary[0].0
        var acc1 = ary[0].0 * ary[0].1
        
        var a2 = ary[1].0
        var acc2 = ary[1].0 * ary[1].1
        if (a2 != a1 + 1) {
            acc2 += acc1
        }
        acc2 = max(acc1, acc2)
        for i in stride(from: 2, to: ary.count, by: 1) {
            var a3 = ary[i].0
            var acc3 = ary[i].0 * ary[i].1
            
            acc3 = max(
                acc1 + acc3,
                (a2 == a3-1) ? acc2 : acc2 + acc3
            )
            (a1, a2) = (a2, a3)
            (acc1, acc2) = (acc2, acc3)
        }
        return max(acc1, acc2)
    }
}