class Solution {
  
    func findSmallestSetOfVertices(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var visited = Array(repeating: false, count: n)
        edges.forEach { visited[$0[1]] = true }
        return (0..<n).filter { !visited[$0] }
    }
}