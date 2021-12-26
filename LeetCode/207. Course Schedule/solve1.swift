class Solution {
    func canFinish(_ numCourses: Int, _ prerequisites: [[Int]]) -> Bool {
        let N = numCourses
        var inwards = Array(repeating: [Int](), count: N)
        for pre in prerequisites {
            inwards[pre[0]].append(pre[1])
        }
        
        var visited = Array(repeating: 0, count: N)
        
        func dfs(_ cur: Int) -> Bool {
            visited[cur] = 1
            for inward in inwards[cur] {
                switch visited[inward] {
                    case 0: if !dfs(inward) { return false }
                    case 1: return false
                    default: break
                }
            }
            visited[cur] = 2
            return true
        }
        
        for i in 0..<N {
            if visited[i] == 0 {
                if !dfs(i) { return false }
            }
        }
        return true
    }
}