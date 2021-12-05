class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var freq: [Int: Int] = [:]
        nums.forEach { freq[$0, default: 0] += 1 }
        let sorted = freq.sorted { $0.1 > $1.1 }
        
        return sorted[..<k].map { $0.0 }
    }
}