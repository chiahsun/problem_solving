class Solution {
    func toInt(_ c: Character) -> Int {
        let cur = c.asciiValue
        let head = Character("a").asciiValue
        return Int(cur! - head!)
    }
    
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        var a1 = Array(repeating: 0, count: 26)
        var a2 = Array(repeating: 0, count: 26)
        for c in Array(s1) {
            a1[toInt(c)] += 1
        }
        
        let characters2 = Array(s2)
        var start = 0
        for i in 0..<characters2.count {
            let c = characters2[i]
            a2[toInt(c)] += 1
            if a2[toInt(c)] == a1[toInt(c)] {
                if (0..<26).allSatisfy({ a1[$0] == a2[$0] }) {
                    return true
                }
            } else if (a2[toInt(c)] > a1[toInt(c)]) {
                while start <= i && (a2[toInt(c)] > a1[toInt(c)]) {
                    a2[toInt(characters2[start])] -= 1
                    start += 1
                }
            }
        }
        return false
    }
}