
// 0 -> 1 - > 2
// 2 -> 0
class Solution {
    func dfs(_ visited: inout [Int], _ cur: Int, _ inwards: [[Int]], _ ans: inout [Int]) -> Bool {
        visited[cur] = 1
        for from in inwards[cur] {
            if visited[from] == 1 { return false }
            if visited[from] == 0 {
                if !dfs(&visited, from, inwards, &ans) {
                    return false
                }
            }
        }
        ans.append(cur)
        visited[cur] = 2
        return true
    }
    
    func findOrder(_ numCourses: Int, _ prerequisites: [[Int]]) -> [Int] {
        let N = numCourses
        var visited = Array(repeating: 0, count: N)
        var inwards = Array(repeating: [Int](), count: N)
        for p in prerequisites {
            let (a, b) = (p[0], p[1])
            inwards[a].append(b)
        }
        
        var ans: [Int] = []
        for i in 0..<N {
            if visited[i] == 0 {
                if !dfs(&visited, i, inwards, &ans) {
                    ans = []
                    break
                }
            }
        }
        return ans
    }
}