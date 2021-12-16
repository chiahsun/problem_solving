class Solution {
    func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var E = Array(repeating: [Int](), count: n)
        var leftEdges = edges.count
        for i in 0..<edges.count {
            let e = edges[i]
            E[e[0]].append(i)
            E[e[1]].append(i)
        }
        var q: [Int] = (0..<n).filter { E[$0].count <= 1 }
        var nextq: [Int] = []
        while leftEdges > 1 {
            for cur in q {
                let edgeId = E[cur][0]
                let another = (edges[edgeId][0] == cur) ? edges[edgeId][1] : edges[edgeId][0]
                if let index = E[another].firstIndex(of: edgeId) {
                    E[another].remove(at: index)
                }
                leftEdges -= 1
                if E[another].count == 1 {
                    nextq.append(another)
                }
            }
            q = nextq
            nextq.removeAll()
        }

        return q
    }
}