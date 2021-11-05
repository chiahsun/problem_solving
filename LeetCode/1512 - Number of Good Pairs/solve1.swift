class Solution {
    func numIdenticalPairs(_ nums: [Int]) -> Int {
        var counts: [Int: Int] = [:]
        for x in nums {
            if let oldCnt = counts[x] {
                counts[x]! += 1
            } else {
                counts[x] = 1
            }
        }
        
        return counts.reduce(0, { acc, elem in
            let curCnt = elem.1
            return acc + (curCnt - 1)*curCnt/2
        })
    }
}