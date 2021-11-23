class Solution {
    func getString(_ s: [Character]) -> String {
        var res: [Character] = []
        for c in s {
            if c == "#" {
                if !res.isEmpty {
                    res.removeLast()
                }
            } else {
                res.append(c)
            }
        }
        return String(res)
    }
    
    func backspaceCompare(_ s: String, _ t: String) -> Bool {
        var (s, t) = (Array(s), Array(t))
        // abc### cde###
        
        // a#bc## cde###
        // a#bc## cbe###
        
        // ab#c##
        return getString(s) == getString(t)
    }
}