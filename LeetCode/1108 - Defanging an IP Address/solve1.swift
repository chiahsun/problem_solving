class Solution {
    func defangIPaddr(_ address: String) -> String {
        var ans = ""
        for c in address {
            let s = String(c)
            ans += (s == "." ? "[.]" : s)
        }
        return ans
    }
}