class TrieNode {
    var nexts: [Character: TrieNode] = [:]
    var prefixSum = 0
    var val = 0
}

class MapSum {
    var root = TrieNode()

    init() { }
    
    private func find(_ key: String) -> TrieNode? {
        var p = root
        var pos = key.startIndex
        repeat {
            let c = key[pos]
            if let next = p.nexts[c] { 
                p = next
            } else {
                return nil
            }
            pos = key.index(after: pos)
        } while pos != key.endIndex
        return p
    }
    
    func insert(_ key: String, _ val: Int) {
        var originalVal = 0
        if let p = find(key) {
            originalVal = p.val
        }
        
        var p = root
        var pos = key.startIndex
        repeat {
            let c = key[pos]
            if p.nexts[c] == nil { p.nexts[c] = TrieNode() }
            p = p.nexts[c]!
            p.prefixSum += (val - originalVal)
            pos = key.index(after: pos)
        } while pos != key.endIndex
        p.val = val
    }
    
    func sum(_ prefix: String) -> Int {
       if let p = find(prefix) {
           return p.prefixSum
       }
        return 0
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * let obj = MapSum()
 * obj.insert(key, val)
 * let ret_2: Int = obj.sum(prefix)
 */