extension Character {
    var indexValue: Int {
        switch self {
            case "a": return 0
            case "b": return 1
            case "c": return 2 
            case "d": return 3
            case "e": return 4 
            case "f": return 5 
            case "g": return 6
            case "h": return 7 
            case "i": return 8
            case "j": return 9 
            case "k": return 10 
            case "l": return 11
            case "m": return 12
            case "n": return 13
            case "o": return 14
            case "p": return 15
            case "q": return 16
            case "r": return 17
            case "s": return 18
            case "t": return 19
            case "u": return 20
            case "v": return 21
            case "w": return 22
            case "x": return 23
            case "y": return 24
            case "z": return 25
            default: return -1
        }
    }
}

class TrieNode {
    var end = false
    var nexts: [TrieNode?] = Array(repeating: nil, count: 26)
    
    var isEnd: Bool { return end }
    
    func put(_ characters: [Character], _ startPos: Int) {
        guard startPos < characters.count else {
            end = true
            return
        }
        
        let cIndex = characters[startPos].indexValue
        if nexts[cIndex] == nil {
            nexts[cIndex] = TrieNode()
        }

        if let next = nexts[cIndex] {
            next.put(characters, startPos+1)    
        } 
    }
    
    func advance(_ c: Character) -> TrieNode? {
        guard let next = nexts[c.indexValue] else {
            return nil
        }
        return next
    }
}

class Trie {
    var root = TrieNode()
    var movingNodes: [TrieNode] = []
    
    func put(_ characters: [Character], _ startPos: Int) {
        root.put(characters, startPos)
    }
    
    func advance(_ c: Character) -> Bool {
        var hasEnd = false
        var nextMovingNodes: [TrieNode] = []
        for i in 0..<movingNodes.count {
            let node = movingNodes[i]
            if let next = node.advance(c) {
                hasEnd = hasEnd || next.isEnd
                nextMovingNodes.append(next)
            }
        }
        movingNodes = nextMovingNodes
        if let next = root.advance(c) {
            hasEnd = hasEnd || next.isEnd
            movingNodes.append(next)
        }
        return hasEnd
    }
}

class StreamChecker {
    var trie = Trie()
    
    init(_ words: [String]) {
        for w in words {
            trie.put(Array(w), 0)
        }
    }
    
    func query(_ letter: Character) -> Bool {
        return trie.advance(letter) 
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * let obj = StreamChecker(words)
 * let ret_1: Bool = obj.query(letter)
 */