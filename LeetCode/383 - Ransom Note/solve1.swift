class Solution {
    func canConstruct(_ ransomNote: String, _ magazine: String) -> Bool {
        var d: [Character: Int] = [:]
        for c in magazine {
            d[c, default: 0] += 1
        }
        for c in ransomNote {
            if let count = d[c], count > 0 {
                d[c]! -= 1
            } else {
                return false
            }
        }
        return true
    }
}