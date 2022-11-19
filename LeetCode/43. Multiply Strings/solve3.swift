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
        var a: [Int] = num1.reversed().map { $0.digitValue }
        var b: [Int] = num2.reversed().map { $0.digitValue }
        let (M, N) = (a.count, b.count)
        
        var d = [0]
        for i in 0..<M {
            let v1 = a[i]
            for k in 0..<N {
                let v2 = b[k]
                var carry = v2 * v1 
                var pos = i+k
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

        return String(d.reversed().map { Character.fromDigit($0) })
    }
}