class Solution {
  
    func findSmallestSetOfVertices(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var candidates = Set(0..<n)
        for e in edges { 
            candidates.remove(e[1])
        }
        return Array(candidates)
    }
}