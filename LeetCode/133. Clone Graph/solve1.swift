/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var neighbors: [Node?]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.neighbors = []
 *     }
 * }
 */

class Solution {
    func cloneGraph(_ node: Node?) -> Node? {
        guard let node = node else { return nil }
        
        var visited: [Node?] = Array(repeating: nil, count: 1)
        
        func dfs(_ node: Node) -> Node {
            let curVal = node.val
            while curVal >= visited.count { visited.append(nil) }             
            let newNode = Node(curVal)
            visited[curVal] = newNode
            for n in node.neighbors {
                if let n = n {
                    let nextVal = n.val
                    if nextVal < visited.count, let mapped = visited[nextVal] {
                        newNode.neighbors.append(mapped)
                    } else {
                        let nextNode = dfs(n)
                        newNode.neighbors.append(nextNode)
                    }
                }
            }
            return newNode
        }
        
        return dfs(node)
    }
}