class Solution {
    // https://stackoverflow.com/questions/39677330/how-does-string-substring-work-in-swift
    func findRepeatedDnaSequences(_ s: String) -> [String] {
        var s = Array(s)
        
        var ss = Set<String>()
        var ss2 = Set<String>()
        for i in 0..<max(0, s.count-9) {
            let cur = String(s[i..<(i+10)])
            if ss.contains(cur) {
                ss2.insert(cur)
            } else {
                ss.insert(cur)
            }
        }
        
        return [String](ss2)
    }
}