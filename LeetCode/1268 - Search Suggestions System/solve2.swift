class TrieNode {
    var end = false
    var nexts: [Character: TrieNode] = [:]
    
    func put(_ charcters: [Character], _ pos: Int) {
        if pos >= charcters.count { end = true; return }
        let c = charcters[pos]
        if nexts[c] == nil { nexts[c] = TrieNode() }
        nexts[c]!.put(charcters, pos+1)
    }
    
    func search(_ completions: inout [String], _ cur: inout [Character], _ searchWord: [Character], _ pos: Int) -> Bool {
        if completions.count >= 3 { return true }
        if pos >= searchWord.count && end { completions.append(String(cur)) }
        if completions.count >= 3 { return true }
        if pos < searchWord.count {
            let c = searchWord[pos]
            if let next = nexts[c] {
                cur.append(c)
                next.search(&completions, &cur, searchWord, pos+1)
                cur.removeLast()
            }
        } else {
            for c in nexts.keys.sorted(by: <) {
                cur.append(c)
                var done = nexts[c]!.search(&completions, &cur, searchWord, pos+1)
                cur.removeLast()
                if done { return true }
            }
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
        var searchPrefix: [Character] = []
        for c in Array(searchWord) {
            var completions: [String] = []
            var cur: [Character] = []
            searchPrefix.append(c)
            // TODO: Change to new node
            root.search(&completions, &cur, searchPrefix, 0)
            ans.append(completions)
        }
        return ans
    }
}