class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var d: Set<Character> = []
        var maxLen = 0
        var start = 0
        var characters = Array(s)
        for i in 0..<characters.count {
            let c = characters[i]
            let end = i+1
            if d.contains(c) {
                while start < i && d.contains(c) {
                    if characters[start] != c {
                        d.remove(characters[start])   
                        start += 1
                    } else {
                        start += 1
                        break
                    }      
                }
            } else {
                d.insert(c)
                maxLen = max(maxLen, end - start)           
            }
            if maxLen > characters.count - start { break }     
        }
        return maxLen
    }
}