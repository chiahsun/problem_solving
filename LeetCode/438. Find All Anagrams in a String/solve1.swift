extension Character {
    static let aAsciiValue = Character("a").asciiValue!
    var offset: Int {
        get {
            return Int(self.asciiValue! - Character.aAsciiValue)
        }
    }
}

class Solution {
    func getAry(_ s: [Character]) -> [Int] {
        var A = Array(repeating: 0, count: 26)
        for c in s {
            A[c.offset] += 1
        }
        return A
    }
    
    func findAnagrams(_ s: String, _ p: String) -> [Int] {
        guard p.count <= s.count else { return [] }
        
        let s1 = Array(s)
        let s2 = Array(p)
        
        var S = getAry(Array(s1[0..<s2.count]))
        var P = getAry(s2)
        
        var ans: [Int] = []
        if S == P { ans.append(0) }
        for i in s2.count..<s1.count {
            S[s1[i].offset] += 1
            S[s1[i-s2.count].offset] -= 1
            if S == P {
                ans.append(i-s2.count+1)
            }
        }
        return ans
    }
}