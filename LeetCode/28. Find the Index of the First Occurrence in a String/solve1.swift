class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        guard needle.count > 0 else { return 0 }
        guard haystack.count >= needle.count else { return -1 }
        
        var posHaystack = haystack.startIndex
        var endSubHaystack = haystack.index(posHaystack, offsetBy: needle.count)
        var index = 0
        while true {
            if haystack[posHaystack..<endSubHaystack] == needle {
               return index
            }
            if endSubHaystack == haystack.endIndex {
                break
            }
            index += 1
            posHaystack = haystack.index(after: posHaystack)
            endSubHaystack = haystack.index(after: endSubHaystack)
        }
        
        return -1
    }
}