class Solution {
    func findMinHeightTrees(_ n: Int, _ edges: [[Int]]) -> [Int] {
        var A = Array(repeating: Set<Int>(), count: n)
        var left = edges.count
        for e in edges {
            A[e[0]].insert(e[1])
            A[e[1]].insert(e[0])
        }
        var last = 0
        while left > 1 {
            let toRemove = (0..<n).filter { A[$0].count == 1 }
            for i in toRemove {
                for another in A[i] {
                    A[another].remove(i)
                    A[i].remove(another)
                    last = another
                    left -= 1
                    break
                }
            }
        }
        if left == 0 { return [last] }
        
        return (0..<n).filter { A[$0].count == 1 }
    }
}