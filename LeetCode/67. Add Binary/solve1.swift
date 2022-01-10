class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        var ans = ""
        var a = Array(a.reversed())
        var b = Array(b.reversed())
        var carry = 0
        for i in 0..<max(a.count, b.count) {
            if i < a.count, case let d = a[i] { carry += (d == "1") ? 1 : 0 }
            if i < b.count, case let d = b[i] { carry += (d == "1") ? 1 : 0 }
            ans += (carry % 2 > 0) ? "1" : "0"
            carry /= 2
        }
        if carry > 0 { ans += "1" }
        return String(ans.reversed())
    }
}