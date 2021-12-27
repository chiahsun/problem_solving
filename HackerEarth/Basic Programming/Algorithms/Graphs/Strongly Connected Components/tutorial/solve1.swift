let params = readLine()!.split(separator: " ")
let N = Int(params[0])!
let M = Int(params[1])!

// print("N: \(N) M: \(M)")

var E: [[Int]] = Array(repeating: [], count: N)
var RE: [[Int]] = Array(repeating: [], count: N)
for _ in 0..<M {
    let params = readLine()!.split(separator: " ")
    let a = Int(params[0])!-1
    let b = Int(params[1])!-1
    E[a].append(b)
    RE[b].append(a)
}
// print("E: \(E)")

func topologicalSortReversedOrder(_ N: Int, _ E: [[Int]]) -> [Int] {
    var visited = Array(repeating: false, count: N)
    var res: [Int] = []
    func dfs(_ cur: Int) {
        visited[cur] = true
        for next in E[cur] where !visited[next] {
            dfs(next)
        }
        res.append(cur)
    }
    for i in 0..<N where !visited[i] {
        dfs(i)
    }
    return res.reversed()
}

func findSCC(_ N: Int, _ E: [[Int]], _ RE: [[Int]]) -> [Int] {
    let order = topologicalSortReversedOrder(N, RE)
    // print("order: \(order)")
    var scc = Array(repeating: -1, count: N)
    func dfs(_ cur: Int, _ id: Int) {
        scc[cur] = id
        for next in E[cur] where scc[next] == -1 {
            dfs(next, id)
        }
    }

    for i in order where scc[i] == -1 {
        dfs(i, i)
    }
    return scc
}

let scc = findSCC(N, E, RE)
// print("scc: \(scc)")
var m: [Int: Int] = [:]
for id in scc {
    m[id, default: 0] += 1
}

var odds = 0
var evens = 0
for (_, count) in m {
    if count % 2 == 0 { evens += count }
    else              { odds += count }
}
print(odds-evens)
