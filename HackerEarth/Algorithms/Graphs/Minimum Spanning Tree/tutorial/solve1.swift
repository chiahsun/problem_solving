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

edges.sort()
var E = 0
var ans = 0
var uf = UnionFind(N)

for e in edges {
    if E+1 >= N { break }
    if uf.findRoot(e.u) != uf.findRoot(e.v) {
        uf.makeUnion(e.u, e.v)
        ans += e.w
        E += 1
    }
}

print(ans)
