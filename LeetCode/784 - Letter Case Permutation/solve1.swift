class Solution {
    func next(_ characters: inout [Character], _ pos: Int, _ ans: inout [String]) {
        if pos != characters.count-1 {
            perm(&characters, pos+1, &ans)     
        } else {
            ans.append(String(characters))   
        }
    }
    
    func perm(_ characters: inout [Character], _ pos: Int, _ ans: inout [String]) {
        let c = characters[pos]
        if c >= "0" && c <= "9" {
            next(&characters, pos, &ans)
        } else {
            characters[pos] = Character(characters[pos].lowercased())
            next(&characters, pos, &ans)
            characters[pos] = Character(characters[pos].uppercased())
            next(&characters, pos, &ans)
        }
    }
    
    func letterCasePermutation(_ s: String) -> [String] {
        var ans: [String] = []
        var characters = Array(s)
        perm(&characters, 0, &ans)
        return ans
    }
}