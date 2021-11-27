extension Character {
    var digitValue: Int {
        get {
            switch self {
                case "0": return 0
                case "1": return 1
                case "2": return 2
                case "3": return 3
                case "4": return 4
                case "5": return 5
                case "6": return 6
                case "7": return 7
                case "8": return 8
                case "9": return 9
                default: return 0
            }
        }
    }
    
    static func makeFromDigit(_ val: Int) -> Character {
        switch val {
                case 0: return "0"
                case 1: return "1"
                case 2: return "2"
                case 3: return "3"
                case 4: return "4"
                case 5: return "5"
                case 6: return "6"
                case 7: return "7"
                case 8: return "8"
                case 9: return "9"
                default: return "0"
        }
    }
}

class Solution {
    func addStrings(_ num1: String, _ num2: String) -> String {
        let (s1, s2) = (Array(num1), Array(num2))
        var (i, k) = (s1.count-1, s2.count-1)
        var ans: [Character] = []
        var carry = 0
        while i >= 0 || k >= 0 || carry > 0 {
            let a = i >= 0 ? s1[i].digitValue : 0
            let b = k >= 0 ? s2[k].digitValue : 0
            carry += (a + b)
            ans.append(Character.makeFromDigit(carry % 10))
            carry /= 10
            i -= 1
            k -= 1
        }
        return String(ans.reversed())
    }
}