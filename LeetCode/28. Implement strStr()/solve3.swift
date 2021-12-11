class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        guard needle.count > 0 else { return 0 }
        var haystack = Array(haystack)
        var needle = Array(needle)
        let N = needle.count
        var partialMatch = Array(repeating: 0, count: N)
       
        var prev = 0
        for i in 1..<N {
            while needle[i] != needle[prev] && prev != 0 {
                prev =  partialMatch[prev-1]  
            }
            let cur = prev + (needle[i] == needle[prev] ? 1 : 0)
            (partialMatch[i], prev) = (cur, cur)
        }
 
        var posHaystack = 0
        var posNeedle = 0
        while posHaystack < haystack.count {
            let c = haystack[posHaystack]
            if c == needle[posNeedle] {
                posNeedle += 1
                posHaystack += 1
                if posNeedle == N {
                    return posHaystack-N
                }
            } else if posNeedle == 0 {
                posHaystack += 1
            } else {
                posNeedle = partialMatch[posNeedle-1]
            }
        }
        
        return -1
    }
}