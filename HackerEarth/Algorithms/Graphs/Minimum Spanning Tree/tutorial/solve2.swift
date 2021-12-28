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

var edges: [[Edge]] = Array(repeating: [], count: N)
for _ in 0..<M {
    let params = readLine()!.split(separator: " ")
    let u = Int(params[0])!-1
    let v = Int(params[1])!-1
    let w = Int(params[2])!
    let e = Edge(u: u, v: v, w: w)
    edges[u].append(e)
    edges[v].append(e)
}

//    0
//  1   2
// 3 4
class MinHeap {
    var A:[Edge] = []

    func add(_ edge: Edge) {
        A.append(edge)
        swimUp(A.count-1)
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

var E = 0
var ans = 0

var mh = MinHeap()
var visited = Array(repeating: false, count: N)
visited[0] = true

for e in edges[0] { mh.add(e) }

while E+1 < N, case let minEdge = mh.popMin() {
    if !visited[minEdge.u] || !visited[minEdge.v] {
        let next = !visited[minEdge.u] ? minEdge.u : minEdge.v
        visited[next] = true
        ans += minEdge.w
        E += 1
        for e in edges[next] { mh.add(e) }
    }
}

print(ans)
