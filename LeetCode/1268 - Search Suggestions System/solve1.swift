extension Character {
     static func fromIndexValue(_ i: Int) -> Character {
         switch i {
             case 0 : return "a"
             case 1 : return "b"
             case 2 : return "c"
             case 3 : return "d"
             case 4 : return "e"
             case 5 : return "f"
             case 6 : return "g"
             case 7 : return "h"
             case 8 : return "i"
             case 9 : return "j"
             case 10: return "k"
             case 11: return "l"
             case 12: return "m"
             case 13: return "n"
             case 14: return "o"
             case 15: return "p"
             case 16: return "q"
             case 17: return "r"
             case 18: return "s"
             case 19: return "t"
             case 20: return "u"
             case 21: return "v"
             case 22: return "w"
             case 23: return "x"
             case 24: return "y"
             case 25: return "z"
             default: return "?"
         }
     }
    
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
    
    func put(_ charcters: [Character], _ pos: Int) {
        if pos >= charcters.count { end = true; return }
        let index = charcters[pos].indexValue
        if nexts[index] == nil { nexts[index] = TrieNode() }
        nexts[index]!.put(charcters, pos+1)
    }
    
    func search(_ completions: inout [String], _ cur: inout [Character], _ searchWord: [Character], _ pos: Int) -> Bool {
        if completions.count >= 3 { return true }
        if pos >= searchWord.count && end { completions.append(String(cur)) }
        if completions.count >= 3 { return true }
        if pos < searchWord.count {
            let index = searchWord[pos].indexValue
            if let next = nexts[index] {
                cur.append(Character.fromIndexValue(index))
                next.search(&completions, &cur, searchWord, pos+1)
                cur.removeLast()
            }
        } else {
            for i in 0..<26 {
                if let next = nexts[i] {
                    cur.append(Character.fromIndexValue(i))
                    var done = next.search(&completions, &cur, searchWord, pos+1)
                    cur.removeLast()
                    if done { return true }
                }
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