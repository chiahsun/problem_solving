class Solution {
    func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var A = Array(repeating: Set<Int>(), count: n)
        var leftEdges = edges.count
        for e in edges {
            A[e[0]].insert(e[1])
            A[e[1]].insert(e[0])
        }
        var q: [Int] = (0..<n).filter { A[$0].count <= 1 }
        var nextq: [Int] = []
        while leftEdges > 1 {
            for cur in q {
                let another = A[cur].first!
                A[another].remove(cur)
                A[cur].remove(another)
                leftEdges -= 1
                if A[another].count == 1 {
                    nextq.append(another)
                }
            }
            q = nextq
            nextq.removeAll()
        }

        return q
    }
}