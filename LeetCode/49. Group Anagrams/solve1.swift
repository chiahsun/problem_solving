// https://developer.apple.com/documentation/swift/hashable
struct Anagram: Hashable {
    static let aAsciiValue = Character("a").asciiValue!
    var A = Array(repeating: 0, count: 26)
    
    init(_ s: String) {
        s.forEach { c in
            A[Int(c.asciiValue! - Anagram.aAsciiValue)] += 1
        }
    }
    
    static func == (a: Anagram, b: Anagram) -> Bool {
        return a.A == b.A
    }

    func hash(into hasher: inout Hasher) {
        hasher.combine(A)
    }
}

class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var d: [Anagram: [String]] = [:]
        
        for s in strs { 
            d[Anagram(s), default: []].append(s)
        }
        var ans: [[String]] = []
        for v in d.values {
            ans.append(v)
        }
        return ans
    }
}