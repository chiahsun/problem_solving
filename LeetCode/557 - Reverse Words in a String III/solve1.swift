class Solution {
    func reverseWord(_ characters: inout [Character], _ i: Int, _ k: Int) {
        var (i, k) = (i, k-1)
        while i < k {
            (characters[i], characters[k]) = (characters[k], characters[i])
            i += 1
            k -= 1
        }
    }
    func reverseWords(_ s: String) -> String {
        var characters = Array(s)
        var i = 0
        let N = characters.count
        while i < N {
            if characters[i] == " " {
                i += 1
            } else {
                var (start, k) = (i, i)
                while k < N && characters[k] != " " {
                    k += 1
                }
                reverseWord(&characters, i, k)
                i = k
            }
        }
        return String(characters)
    }
}