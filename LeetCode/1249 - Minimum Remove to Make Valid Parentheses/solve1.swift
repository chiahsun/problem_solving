class Solution {
    func minRemoveToMakeValid(_ s: String) -> String {
        var s = Array(s)
        var nl = 0
        for i in 0..<s.count {
            let cur = s[i]
            if cur == "(" { nl += 1 }
            else if cur == ")" {
                if nl == 0 { s[i] = "-" } 
                else       { nl -= 1}
            }
        }
        for i in stride(from: s.count-1, to: -1, by: -1) {
            if nl == 0 { break }
            let cur = s[i]
            if cur == "(" { 
                nl -= 1 
                s[i] = "-"
            }
        }
        return String(s.filter { $0 != "-" })
    }
}