//Solution goes in Sources
class SumOfMultiples {
    static func toLimit(_ limit: Int, inMultiples: [Int]) -> Int {
        let multiples = inMultiples.filter { $0 > 0 }
        guard !multiples.isEmpty && limit > 0 else { return 0 }
        
        var candidates = multiples
        var ans = 0
        var last = 0
        while let minIndex = candidates.indices.min(by: {
            candidates[$0] < candidates[$1]
        }) {
            let curVal = candidates[minIndex]
            if curVal >= limit { break }
            candidates[minIndex] = curVal + multiples[minIndex]
            if curVal == last { continue }
            ans += curVal
            last = curVal
        }
        return ans
    }
}
