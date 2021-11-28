extension Character {
    static func fromDigit(_ x: Int) -> Character {
        switch x {
            case 0: return "A"
            case 1: return "T"
            case 2: return "C"
            case 3: return "G"
            default: return "?"
        }
    }
    var intValue: Int {
        get {
            switch self {
                case "A": return 0
                case "T": return 1
                case "C": return 2
                case "G": return 3
                default: return 0
            }
        }
    }
}

class Solution {
    func findRepeatedDnaSequences(_ s: String) -> [String] {
        var s = Array(s)
        
        var ss = Set<Int>()
        var ss2 = Set<Int>()
        var cur = 0
        let mod = Int(pow(Double(4),Double(10)))
        for i in 0..<s.count {
            cur += s[i].intValue
            if i >= 9 {
                if ss.contains(cur) {
                    ss2.insert(cur)
                } else {
                    ss.insert(cur)
                }            
            }
    
            cur *= 4
            cur %= mod
        }
        
        var ans: [String] = []
        for val in ss2 {
            var val = val
            var now: [Character] = []
            for i in 0..<10 {
                now.append(Character.fromDigit(val % 4))
                val /= 4
            }
            ans.append(String(now.reversed()))
        }

        return ans
    }
}