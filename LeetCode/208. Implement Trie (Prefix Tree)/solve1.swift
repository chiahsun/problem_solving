class TrieNode {
    var d: [Character: TrieNode] = [:]
    var end = false
    
    func put(_ word: [Character], _ pos: Int) {
        if pos >= word.count { end = true; return }
        
        let c = word[pos]
        if d[c] == nil { d[c] = TrieNode() }
        d[c]!.put(word, pos+1)
    }
    
    func get(_ word: [Character], _ pos: Int) -> TrieNode? {
        if pos >= word.count {
            return self
        }
        if let next = d[word[pos]] {
            return next.get(word, pos+1)
        }
        
        return nil
        
    }
}
class Trie {
    var root = TrieNode()
    
    init() { }
    
    func insert(_ word: String) { root.put(Array(word), 0) }
    
    func search(_ word: String) -> Bool {
        guard let lastNode = root.get(Array(word), 0) else { return false }
        return lastNode.end
    }
    
    func startsWith(_ prefix: String) -> Bool {
        guard let lastNode = root.get(Array(prefix), 0) else { return false }
        return true
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie()
 * obj.insert(word)
 * let ret_2: Bool = obj.search(word)
 * let ret_3: Bool = obj.startsWith(prefix)
 */