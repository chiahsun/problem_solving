let params = readLine()!.split(separator: " ")
let N = Int(params[0])!
let M = Int(params[1])!

struct Edge: Comparable {
    let u, v, w: Int
    func comparedTo(_ other: Edge) -> Int {
        if w < other.w { return -1 }
        else if w > other.w { return 1 }
        return 0
    }
    // https://developer.apple.com/documentation/swift/comparable
    static func < (a: Edge, b: Edge) -> Bool {
        return a.comparedTo(b) < 0
    }
}

var edges: [Edge] = []
for _ in 0..<M {
    let params = readLine()!.split(separator: " ")
    let u = Int(params[0])!-1
    let v = Int(params[1])!-1
    let w = Int(params[2])!
    edges.append(Edge(u: u, v: v, w: w))
}

//    0
//  1   2
// 3 4
class MinHeap {
    var A:[Edge]
    init(_ edges: [Edge]) { 
        self.A = edges
        for i in stride(from: 0, to: A.count, by: 1) {
            swimUp(i)
        }
    }

    func swimUp(_ pos: Int) {
        var pos = pos
        while pos > 0, case let parent = (pos-1)/2, A[pos] < A[parent] {
            A.swapAt(parent, pos)
            pos = parent
        }
    }

    func popMin() -> Edge {
        var minEdge = A[0]
        let lastPos = A.count-1
        if lastPos != 0 { A.swapAt(0, lastPos) }
        A.removeLast()
        var pos = 0
        while case let leftPos = 2*pos+1, leftPos < A.count {
            var minPos = pos
            if A[leftPos] < A[pos] { minPos = leftPos }
            if case let rightPos = 2*pos+2, rightPos < A.count, A[rightPos] < A[minPos] { minPos = rightPos }
            if minPos != pos {
                A.swapAt(minPos, pos)
                pos = minPos
            } else {
                break
            }
        }
        return minEdge
    }
}

class UnionFind {
    var id: [Int] 
    var count: [Int]
    init(_ N: Int) { id = Array(0..<N); count = Array(repeating: 1, count: N) }

    func makeUnion(_ a: Int, _ b: Int) {
        let ra = findRoot(a)
        let rb = findRoot(b)
        if ra != rb {
            if count[ra] >= count[rb] { 
                id[rb] = ra; count[ra] += count[rb]
            } else {
                id[ra] = rb; count[rb] += count[ra]
            }
        }
    }

    func findRoot(_ a: Int) -> Int {
        guard id[a] != a else { return a }

        let root = findRoot(id[a])
        id[a] = root
        return root
    }
}

var mh = MinHeap(edges)
var E = 0
var ans = 0
var uf = UnionFind(N)

while E+1 < N {
    let e = mh.popMin()
    if uf.findRoot(e.u) != uf.findRoot(e.v) {
        uf.makeUnion(e.u, e.v)
        ans += e.w
        E += 1
    }
}

print(ans)
