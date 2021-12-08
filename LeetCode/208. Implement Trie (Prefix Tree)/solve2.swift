class TrieNode {
    var d: [Character: TrieNode] = [:]
    var end = false
}

class Trie {
    var root = TrieNode()
    
    init() { }
    
    func insert(_ word: String) { 
        var p = root
        var pos = word.startIndex
        
        repeat {
            let c = word[pos]
            if p.d[c] == nil { p.d[c] = TrieNode() }
            p = p.d[c]!
            pos = word.index(after: pos)        
        } while pos != word.endIndex
        
        p.end = true 
    }
    
    func search(_ word: String) -> Bool {
        guard let lastNode = find(word) else { return false }
        return lastNode.end
    }
    
    func startsWith(_ prefix: String) -> Bool {
        guard let lastNode = find(prefix) else { return false }
        return true
    }
         
    private func find(_ word: String) -> TrieNode? {
        var p = root
        var pos = word.startIndex
        
        repeat {
            let c = word[pos]
            if let next = p.d[c] {
                p = next
                pos = word.index(after: pos)
            } else {
                return nil
            }
        } while pos != word.endIndex
        
        return p
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie()
 * obj.insert(word)
 * let ret_2: Bool = obj.search(word)
 * let ret_3: Bool = obj.startsWith(prefix)
 */