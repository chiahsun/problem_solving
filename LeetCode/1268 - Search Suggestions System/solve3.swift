class TrieNode {
    var end = false
    var nexts: [Character: TrieNode] = [:]
    
    func put(_ charcters: [Character], _ pos: Int) {
        if pos >= charcters.count { end = true; return }
        let c = charcters[pos]
        if nexts[c] == nil { nexts[c] = TrieNode() }
        nexts[c]!.put(charcters, pos+1)
    }
    
    func advance(_ c: Character) -> TrieNode? {
        if let next = nexts[c] {
            return next
        }
        return nil
    }
    
    func search(_ completions: inout [String], _ cur: inout [Character]) -> Bool {
        if completions.count >= 3 { return true }
        if end { completions.append(String(cur)) }
        if completions.count >= 3 { return true }
        
        for c in nexts.keys.sorted(by: <) {
            cur.append(c)
            var done = nexts[c]!.search(&completions, &cur)
            cur.removeLast()
            if done { return true }
        }
        
        return completions.count >= 3
    }
}

class Solution {
    func suggestedProducts(_ products: [String], _ searchWord: String) -> [[String]] {
        var root = TrieNode()
        for product in products {
            root.put(Array(product), 0)
        }
        
        var ans: [[String]] = []
        var prefix: [Character] = []
        var node: TrieNode? = root
        for c in Array(searchWord) {
            if let cur = node?.advance(c) {
                prefix.append(c)
                var completions: [String] = []
                cur.search(&completions, &prefix)
                ans.append(completions)
                node = cur
            } else {
                node = nil
                ans.append([])
            }            
        }
        return ans
    }
}