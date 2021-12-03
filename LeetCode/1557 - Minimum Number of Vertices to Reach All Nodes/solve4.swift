class Solution {
  
    func findSmallestSetOfVertices(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var visited = Array(repeating: false, count: n)
        edges.forEach { visited[$0[1]] = true }
        var ans: [Int] = []
        for i in 0..<n {
            if !visited[i] {
                ans.append(i)
            }
        }
        return ans
    }
}