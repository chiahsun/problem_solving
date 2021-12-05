class Solution {
    func frequencySort(_ s: String) -> String {
        var d: [Character: Int] = [:]
        s.forEach { d[$0, default: 0] += 1 }
        let characterOrder = d.sorted { $0.1 > $1.1 }.map { $0.0 }
        for (index, c) in characterOrder.enumerated() {
            d[c] = index
        }
        return String(Array(s).sorted { d[$0]! < d[$1]! })
    }
}