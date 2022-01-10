class Solution {
    func addBinary(_ a: String, _ b: String) -> String {
        let a = Array(a), b = Array(b)
        var ans: [Character] = []
        var carry = 0, i = a.count-1, k = b.count-1
        while i >= 0 || k >= 0 || carry > 0 {
            // print("\(i) \(k) \(carry)")
            if i >= 0 { let d = a[i]; carry += (d == "1" ? 1 : 0); i -= 1 }
            if k >= 0 { let d = b[k]; carry += (d == "1" ? 1 : 0); k -= 1 }
            ans.append((carry % 2 > 0) ? "1" : "0")
            carry /= 2
        }
        return String(ans.reversed())
    }
}