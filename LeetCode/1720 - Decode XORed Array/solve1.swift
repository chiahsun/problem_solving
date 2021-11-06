class Solution {
    func decode(_ encoded: [Int], _ first: Int) -> [Int] {
        var ans: [Int] = [first]
        
        encoded.reduce(first, { acc, elem in
            let cur = acc ^ elem                
            ans.append(cur)
            return cur
        })
        
        return ans
    }
}