extension Character {
    static func fromDigit(_ x: Int) -> Character {
        switch x {
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
}

class Solution {
    func multiply(_ num1: String, _ num2: String) -> String {
        var s1 = Array(num1)
        var s2 = Array(num2)
        let (M, N) = (s1.count, s2.count)
        
        var d = [0]
        for i in stride(from: M-1, to: -1, by: -1) {
            let v1 = s1[i].digitValue
            for k in stride(from: N-1, to: -1, by: -1) {
                let v2 = s2[k].digitValue
                var carry = v2 * v1 
                var pos = (M-i-1)+(N-k-1)
                while carry > 0 {
                    carry += (pos < d.count ? d[pos] : 0)
                    if pos < d.count {
                        d[pos] = carry % 10
                    } else {
                        while d.count < pos {
                           d.append(0)
                        }
                        d.append(carry % 10)
                    }
                    pos += 1
                    carry /= 10
                }
            }
        }

        return String(d.map { Character.fromDigit($0) }.reversed())
    }
}