class Solution {
    func frequencySort(_ s: String) -> String {
        var d: [Character: Int] = [:]
        s.forEach { d[$0, default: 0] += 1 }
        let characterOrder = d.sorted { $0.1 > $1.1 }
        var ans = ""
        for (c, count) in characterOrder {
            ans.append(String(repeating: c, count: count))
        }
        return ans
    }
}