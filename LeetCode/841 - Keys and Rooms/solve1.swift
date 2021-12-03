class Solution {
    func canVisitAllRooms(_ rooms: [[Int]]) -> Bool {
        let N = rooms.count
        var visited = Array(repeating: false, count: N)
        var candidates: [Int] = [0]
        while let cur = candidates.popLast() {
            if !visited[cur] {
                visited[cur] = true
                for next in rooms[cur] where !visited[next] {
                    candidates.append(next)
                }
            }
        }
        return visited.allSatisfy { $0 }
    }
}