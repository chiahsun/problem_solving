/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Codec {
    func serialize(_ root: TreeNode?) -> String {
        guard let root = root else { return "[]" }
        
        var q: [TreeNode?] = [root]
        var qNext: [TreeNode?] = []
        var res: [String] = []
        while !q.isEmpty {
            while !q.isEmpty  {
                let cur = q.removeLast()
                if let curExisted = cur {
                    res.append(String(curExisted.val))
                    if let left = curExisted.left { qNext.append(left) }
                    else                          { qNext.append(nil) }
            
                    if let right = curExisted.right { qNext.append(right) }
                    else                            { qNext.append(nil) }
                } else {
                    res.append("null")
                }
            }          
            qNext = qNext.reversed()
            q = qNext
            qNext.removeAll()
        }
        while let last = res.last, last == "null" { res.removeLast() }
        return "[" + res.joined(separator: ",") + "]"
    }
    
    func deserialize(_ data: String) -> TreeNode? {
        guard data != "[]" else { return nil }
        let startindex = data.index(data.startIndex, offsetBy: 1)
        let endIndex = data.index(data.startIndex, offsetBy: data.count-1)
        var elements = data[startindex..<endIndex].components(separatedBy: ",")

        let root = TreeNode(Int(elements[0])!)
        var q: [TreeNode] = [root]
        var qNext: [TreeNode] = []
        
        var posElements = 1
        while !q.isEmpty {
            while !q.isEmpty {
                var cur = q.removeLast()
                if posElements < elements.count {
                    let elem = elements[posElements]
                    if elem == "null" { }
                    else { 
                        let newNode = TreeNode(Int(elem)!)
                        cur.left = newNode
                        qNext.append(newNode)
                    }
                    posElements += 1
                }
                if posElements < elements.count {
                    let elem = elements[posElements]
                    if elem == "null" { }
                    else  {
                        let newNode = TreeNode(Int(elem)!)
                        cur.right = newNode
                        qNext.append(newNode)
                    }
                    posElements += 1
                }
            }
            qNext = qNext.reversed()
            q = qNext
            qNext.removeAll()
        }
        
        return root
    }
}

// Your Codec object will be instantiated and called as such:
// var ser = Codec()
// var deser = Codec()
// deser.deserialize(ser.serialize(root))