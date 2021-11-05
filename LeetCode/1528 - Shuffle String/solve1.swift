class Solution {
    func restoreString(_ s: String, _ indices: [Int]) -> String {
        var characters = Array(s)
        var done = Array(repeating: false, count: indices.count)
        for index in indices.indices {
            if !done[index] {
                var i = index
                var c = characters[i]

                while !done[i] {
                    let pos = indices[i]
                    
                    let backup = characters[pos]
                    characters[pos] = c
                    done[i] = true
                    
                    c = backup
                    i = pos
                }
            }
        }
        return String(characters)
    }
}