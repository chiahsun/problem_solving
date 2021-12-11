class Solution {
    // aaaaaaaaab
    // aaaab
    
    // abababzz
    // 00
    //   1234
    //       00
    func strStr(_ haystack: String, _ needle: String) -> Int {
        guard needle.count > 0 else { return 0 }
        var haystack = Array(haystack)
        var needle = Array(needle)
        let N = needle.count
        var partialMatch = Array(repeating: 0, count: N)
        // Brute force O(N^2)
        /*for begin in 1..<N {
            for i in 0..<(N-begin) {
                if needle[begin+i] == needle[i] {
                    partialMatch[begin+i] = max(partialMatch[begin+i], i+1)
                } else {
                    break
                }
            }
        }*/
        
        // We use dp to compute suffix as prefix partial matching table
        // This part should not use the brute force O(N^2) algorithm
        for i in 1..<N {
            var prev = partialMatch[i-1]
            if prev == 0 {
                if needle[i] == needle[0] {
                    partialMatch[i] = 1
                }
            } else {
                while needle[i] != needle[prev] && prev != 0 {
                    prev =  partialMatch[prev-1]  
                }
                if prev == 0 {
                    if (needle[i] == needle[0]) {
                        partialMatch[i] = 1
                    }
                } else {
                    partialMatch[i] = prev+1
                }
            }
        }
        // print("\(partialMatch)")
        var posHaystack = 0
        var posNeedle = 0
        while posHaystack < haystack.count {
            let c = haystack[posHaystack]
            // print("c: \(c)")
            // print("posHaystack: \(posHaystack) posNeedle: \(posNeedle)")
            
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
                // print("Set posNeedle as partial match \(posNeedle)")
            }
        }
        
        return -1
    }
}