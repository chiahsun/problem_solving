// https://stackoverflow.com/questions/24092884/get-nth-character-of-a-string-in-swift-programming-language
extension String {
    subscript(i: Int) -> Character { self[index(startIndex, offsetBy: i)]  }
}

class Solution {
    func addStrings(_ num1: String, _ num2: String) -> String {
        var (i, k) = (num1.count-1, num2.count-1)
        var ans = ""
        var carry = 0
        while i >= 0 || k >= 0 || carry > 0 {
            let a = i >= 0 ? num1[i].wholeNumberValue! : 0
            let b = k >= 0 ? num2[k].wholeNumberValue! : 0
            carry += (a + b)
            ans.append(String(carry % 10))
            carry /= 10
            i -= 1
            k -= 1
        }
        return String(ans.reversed())
    }
}