class Solution {
    func longestPalindrome(_ s: String) -> String {
        let characters = Array(s)
        let N = characters.count
        var maxL = 0
        var maxR = 0
        var maxLen = 1
        
        for i in 0..<N {
            for d in [0,1] {
                let (p, q) = (i-maxLen/2, i+maxLen/2+d)
                var ok = p >= 0 && q < N
                
                var (l, r) = (p, q)
                while ok && l < r {
                    if characters[l] != characters[r] {
                        ok = false
                        break
                    }
                    l += 1
                    r -= 1
                }
                if ok {
                    (l, r) = (p, q)
                    
                    while l >= 0 && r < N && characters[l] == characters[r] {
                        l -= 1
                        r += 1
                    }
                    let len = r - l - 1
                    if len > maxLen {
                        maxLen = len
                        maxL = l+1
                        maxR = r-1
                    }
                }
            }
        }
        
        return String(characters[maxL...maxR])
    }
}