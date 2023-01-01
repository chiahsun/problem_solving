class Solution {
    func wordPattern(_ pattern: String, _ s: String) -> Bool {
        var pattern = Array(pattern)
        var s = Array(s)
        var d: [String: Character] = [:]
        var d2: [Character: String] = [:]
        
        var start = 0
        var i = 0
        var posPattern = 0
        while i <= s.count && posPattern < pattern.count {
            if i == s.count || s[i] == " " {
                let word = String(s[start..<i])
                let char = pattern[posPattern]
                if let mapped = d[word], mapped != char {
                    return false
                } else {
                    d[word] = char
                }
                if let mapped = d2[char], mapped != word {
                    return false
                } else {
                    d2[char] = word
                }
                
                posPattern += 1
                start = i+1
            }
            i += 1
        }
        return posPattern == pattern.count && i == s.count+1
    }
}