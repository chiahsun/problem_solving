struct Edge {
    let u: Int
    let v: Int
    let w: Int
    
    static func <(_ a: Edge, _ b: Edge) -> Bool {
        return a.w < b.w
    }
}

//    0
//  1   2
// 3 4 5 6
class MinHeap {
    var A: [Edge] = []
    
    func add(_ e: Edge) {
        var pos = A.count
        A.append(e)
        var cnt = 0
        while pos > 0 {
            let parent = (pos-1)/2
            if A[pos] < A[parent] {
                // Note: tuple swap is slow, we need to use swapAt
                A.swapAt(pos, parent)
                pos = parent
                cnt += 1
            } else {
                break
            }
        }
    }
    
    func popMin() -> Edge {
        let min = A[0]
        let popPos = A.count-1
        A.swapAt(0, popPos)
        A.removeLast()
        var pos = 0
        while case let leftPos = 2*pos+1, leftPos < A.count {
            var minPos = pos
            let rightPos = 2*pos+2
            if leftPos < A.count && A[leftPos] < A[pos] { minPos = leftPos }
            if rightPos < A.count && A[rightPos] < A[minPos] { minPos = rightPos }
            
            if minPos == leftPos {
                A.swapAt(pos, leftPos)
                pos = leftPos
            } else if minPos == rightPos {
                A.swapAt(pos, rightPos)
                pos = rightPos
            } else {
                break
            }
        }
        
        return min
    }
}

class UnionFind {
    var A: [Int] = []
    
    init(_ N: Int) {
        for i in 0..<N { A.append(i) }
    }
    
    func makeUnion(_ a: Int, _ b: Int) {
        var aRoot = findRoot(a)
        var bRoot = findRoot(b)
        if aRoot != bRoot {
            A[aRoot] = bRoot
        }
    }
    
    func findRoot(_ cur: Int) -> Int {
        var parent = A[cur]
        guard parent != cur else { return cur }
        var cur = cur
        while true {
            let grandParent = A[parent]
            if grandParent == parent { break }
            A[cur] = grandParent
            (cur, parent) = (parent, grandParent)
        }
        return parent
    }
}

class Solution {
    func minCostConnectPoints(_ points: [[Int]]) -> Int {
        let N = points.count
        var mh = MinHeap()
        for i in 0..<(N-1) {
            for k in (i+1)..<N {
                let w = abs(points[i][0] - points[k][0]) + abs(points[i][1] - points[k][1])
                mh.add(Edge(u: i, v: k, w: w))
            }
        }
        var uf = UnionFind(N)
        var E = 0
        var ans = 0
        while E+1 < N {
            let e = mh.popMin()
            if uf.findRoot(e.u) != uf.findRoot(e.v) {
                ans += e.w
                uf.makeUnion(e.u, e.v)
                E += 1
            }
        }
        
        return ans
    }
}