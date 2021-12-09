class TrieNode {
    var d: [Character: TrieNode] = [:]
    var end = false
}

class WordDictionary {
    var root = TrieNode()

    init() { }
    
    func addWord(_ word: String) {
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
        return dfs(word, word.startIndex, root)
    }
    
    func dfs(_ word: String, _ pos: String.Index, _ p: TrieNode) -> Bool {
        if pos == word.endIndex {
            return p.end
        }
        
        let c = word[pos]
        let nextPos = word.index(after: pos)
        if c == "." {
            for (_, next) in p.d {
                if dfs(word, nextPos, next) {
                    return true
                }
            }
            return false
        } else {
            if let next = p.d[c] { 
                return dfs(word, nextPos, next)
            }
            return false
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * let obj = WordDictionary()
 * obj.addWord(word)
 * let ret_2: Bool = obj.search(word)
 */