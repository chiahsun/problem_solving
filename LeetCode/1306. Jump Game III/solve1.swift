class Solution {
    func dfs(_ arr: [Int], _ visited: inout [Bool], _ cur: Int) -> Bool {
        if arr[cur] == 0 { return true }
        if visited[cur] { return false }
        visited[cur] = true
        let next = cur+arr[cur]
        if next >= 0 && next < arr.count {
            if dfs(arr, &visited, next) {
                return true
            }
        }
        let prev = cur-arr[cur]
        if prev != next && prev >= 0 && prev < arr.count {
            if dfs(arr, &visited, prev) {
                return true
            }
        }
        return false
    }
    
    func canReach(_ arr: [Int], _ start: Int) -> Bool {
        let N = arr.count
        var visited = Array(repeating: false, count: N)
        return dfs(arr, &visited, start)
    }
}