class Solution {
    func backtracking(_ digits: [Int], _ pos: Int, _ mapping: [[Character]], _ cur: inout [Character], _ ans: inout [String]) {
        guard pos < digits.count else { 
            if !cur.isEmpty {
                ans.append(String(cur))    
            }
            return
        }
        
        for c in mapping[digits[pos]] {
            cur.append(c)
            backtracking(digits, pos+1, mapping, &cur, &ans)
            cur.removeLast()
        }
    }
    
    func letterCombinations(_ digits: String) -> [String] {
        let digits: [Int] = digits.map { Int($0.asciiValue! - Character("0").asciiValue!) }
        var mapping: [[Character]] = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"].map { Array($0) }
       
        var cur: [Character] = []
        var ans: [String] = []
        backtracking(digits, 0, mapping, &cur, &ans)
        
        return ans
    }
}