class TrieNode {
    var d: [Character: TrieNode] = [:]
    var end = false
    
    static func put(_ p: TrieNode, _ word: String, _ pos: String.Index) {
        var p = p
        var pos = pos
        while pos != word.endIndex {
            let c = word[pos]
            if p.d[c] == nil { p.d[c] = TrieNode() }
            p = p.d[c]!
            pos = word.index(after: pos)        
        }
        p.end = true
    }
    
    static func get(_ p: TrieNode, _ word: String, _ pos: String.Index) -> TrieNode? {
        var p = p
        var pos = pos
        
        while pos != word.endIndex {
            let c = word[pos]
            if let next = p.d[c] {
                p = next
                pos = word.index(after: pos)
            } else {
                return nil
            }
        }
        
        return p
    }
}

class Trie {
    var root = TrieNode()
    
    init() { }
    
    func insert(_ word: String) { TrieNode.put(root, word, word.startIndex) }
    
    func search(_ word: String) -> Bool {
        guard let lastNode = TrieNode.get(root, word, word.startIndex) else { return false }
        return lastNode.end
    }
    
    func startsWith(_ prefix: String) -> Bool {
        guard let lastNode = TrieNode.get(root, prefix, prefix.startIndex) else { return false }
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