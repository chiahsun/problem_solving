class Solution {
    func match(_ characters: inout [Character], _ word: [Character], _ pos: Int) -> Int {
        if characters.count - pos < word.count {
            return -1
        }
        
        for i in 0..<word.count {
            if characters[pos+i] != word[i] {
                return -1
            }
        }
        return pos+word.count
    }
    
    func call(_ characters: inout [Character], _ dict: inout [Character: [[Character]]], _ pos: Int, _ dp: inout [Bool]) -> Bool {
        if pos >= characters.count { 
            return true 
        }
        if !dp[pos] {
            return false
        }
        
        if let mapped = dict[characters[pos]] {
            for word in mapped {
                let nextPos = match(&characters, word, pos)
                if nextPos != -1 && call(&characters, &dict, nextPos, &dp) {
                    return true
                }
            }
                      
        }
        
        dp[pos] = false
        return false
    }
    
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        var dict: [Character: [[Character]]] = [:]
        for word in wordDict {
            var characters = Array(word)
            dict[characters[0], default: []].append(characters)
        }
        
        var target = Array(s)
        var dp = Array(repeating: true, count: s.count)
        
        return call(&target, &dict, 0, &dp)
    }
}