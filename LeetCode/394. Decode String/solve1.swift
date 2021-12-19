class Solution {
    // https://stackoverflow.com/questions/26351625/what-is-the-replacement-for-isdigit-for-characters-in-swift
    // https://stackoverflow.com/questions/28445917/what-is-the-most-succinct-way-to-remove-the-first-character-from-a-string-in-swi
    func decodeDigitsString(_ s: String) -> String {
        var s = s
        var digits = ""
        while let first = s.first, "0" <= first && first <= "9" {
            digits.append(first)
            s = String(s.dropFirst())
        }
        let repeatCount = Int(digits)!
        var nL = 0
        var subStr = ""
        while let first = s.first {
            if first == "[" { nL += 1 }
            else if first == "]" { nL -= 1 }
            subStr.append(first)
            s = String(s.dropFirst())
            if nL == 0 { break }
        }
        subStr = String(subStr.dropLast())
        subStr = String(subStr.dropFirst())

        let innerResult = decodeString(subStr)
        return String(repeating: innerResult, count: repeatCount) + decodeString(s)
    }
    
    func decodeString(_ s: String) -> String {
        if s.isEmpty { return "" }
        if let first = s.first, "a" <= first && first <= "z" {
            return String(first) + decodeString(String(s.dropFirst()))
        }
        
        return decodeDigitsString(s)
    }
}