// [[1,3,5],[0,0,7],[2,4,6]] -> 21

struct Tile {
    let i: Int
    let k: Int
    let val: Int
}

enum TileValue: Int {
    case Block = 0, Walkable, Tree
}

class PQ {
    static let NotFound = -1
    
    var A: [Int] = []
    
    var keyToPos: [Int] 
    var values: [Int]
    
    init(_ N: Int) {
        keyToPos = Array(repeating: PQ.NotFound, count: N)
        values = Array(repeating: 0, count: N)
    }
    
    private func add(_ key: Int, _ value: Int) {
        let pos = A.count
        A.append(key)
        keyToPos[key] = pos
        values[key] = value
        swimUp(pos)
    }
    
    func update(_ key: Int, _ value: Int) {
        let pos = keyToPos[key]
        if pos == PQ.NotFound {
            add(key, value)
            return
        }
        
        let oldValue = values[key]
        guard oldValue != value else { return }
        
        values[key] = value
        if value < oldValue { swimUp(pos) }
        else                { swimDown(pos) }
    }
    
    private func lessThanByPos(_ i: Int, _ k: Int) -> Bool {
        values[A[i]] < values[A[k]]
    }
    
    private func swapAtPos(_ i: Int, _ k: Int) {
        keyToPos.swapAt(A[i], A[k])
        A.swapAt(i, k)
    }
    
    //     0
    //  1    2
    // 3 4
    private func swimUp(_ pos: Int) {
        var pos = pos
        
        while pos > 0, case let parent = (pos-1)/2, lessThanByPos(pos, parent) {
            swapAtPos(pos, parent)
            pos = parent
        }
    }
    
     private func swimDown(_ pos: Int) {
         var pos = pos
         
         let N = A.count
         while case let leftPos = 2*pos+1, leftPos < N {
             var minPos = pos
             if lessThanByPos(leftPos, pos) { minPos = leftPos }
             if case let rightPos = 2*pos+2, rightPos < N, lessThanByPos(rightPos, minPos) { minPos = rightPos }
             if pos != minPos { swapAtPos(pos, minPos); pos = minPos }
             else             { break }
         }
     }
    
     func popMin() -> (Int, Int)? {
         guard !A.isEmpty else { return nil }
         
         let minKey = A[0]
         let minValue = values[minKey]
         
         let lastPos = A.count-1
         swapAtPos(0, lastPos)
         
         A.removeLast()
         keyToPos[minKey] = PQ.NotFound
         values[minKey] = 0
         if A.count > 1 {
             swimDown(0)
         }
         
         return (minKey, minValue)
     }
}

class Solution {
    func cutOffTree(_ forest: [[Int]]) -> Int {
        var tiles: [Tile] = [Tile(i: 0, k: 0, val: 1)]
        let M = forest.count
        let N = forest[0].count
        for i in 0..<M {
            for k in 0..<N {
                let f = forest[i][k]
                if f >= TileValue.Tree.rawValue {
                    tiles.append(Tile(i: i, k: k, val: f))
                }
            }
        }
        
        // Check cc count
        var visited = Array(repeating: Array(repeating: false, count: N), count: M)
        let dx: [Int] = [1, -1, 0, 0]
        let dy: [Int] = [0, 0, 1, -1]
        func dfs(_ x: Int, _ y: Int) -> Int {
            visited[x][y] = true
        
            var res = forest[x][y]
            for i in 0..<dx.count {
                let nx = x + dx[i]
                let ny = y + dy[i]
                if nx >= 0 && nx < M && ny >= 0 && ny < N && forest[nx][ny] >= TileValue.Walkable.rawValue && !visited[nx][ny] {
                    res = max(dfs(nx, ny), res)
                }
            }
            return res
        }
        var ncc = 0
        for i in 0..<M {
            for k in 0..<N where forest[i][k] > 0 && !visited[i][k] {
                let res = dfs(i, k)
                if res >= TileValue.Tree.rawValue {
                    ncc += 1
                    if ncc > 1 { return -1 }
                }
            }
        }
        
        tiles.sort(by: { a, b in
            a.val < b.val
        })
        
        var ids = Array(repeating: Array(repeating: 0, count: N), count: M)
        var idToPos: [(Int, Int)] = []
        for i in 0..<M {
            for k in 0..<N where (i == 0 && k == 0) || forest[i][k] >= TileValue.Walkable.rawValue {
                ids[i][k] = idToPos.count
                idToPos.append((i, k))
            }
        }
        
        func shortestPath(_ from: Tile, _ to: Tile) -> Int {
            let unreacheable = M*N
            var g = Array(repeating: Array(repeating: unreacheable, count: N), count: M)
            let idCount = idToPos.count
            var closed = Array(repeating: false, count: idCount)
            var pq = PQ(idCount)
            var startId = ids[from.i][from.k]
            var startF = targetHeuristic(from.i, from.k, to.i, to.k)
            g[from.i][from.k] = 0
            // print("Start from \(from.i) \(from.k)")
            func targetHeuristic(_ curX: Int, _ curY: Int, _ targetX: Int, _ targetY: Int) -> Int {
                return abs(targetX - curX) + abs(targetY - curY)
            }
            pq.update(startId, startF)
            
            while let (minKey, minValue) = pq.popMin() {
                closed[minKey] = true
                let cur = idToPos[minKey]
                let x = cur.0
                let y = cur.1
                // print("[\(x), \(y)](\(minKey)): \(minValue)")
                if x == to.i && y == to.k { break }
                for i in 0..<dx.count {
                    let nx = x + dx[i]
                    let ny = y + dy[i]
                    if nx >= 0 && nx < M && ny >= 0 && ny < N && forest[nx][ny] >= TileValue.Walkable.rawValue {
                        let nextId = ids[nx][ny]
                        if !closed[nextId] {
                            let oldG = g[nx][ny]
                            let newG = g[x][y] + 1
                            if newG < oldG {
                                let h = targetHeuristic(nx, ny, to.i, to.k)
                                let newF = newG + h
                                g[nx][ny] = newG
                                pq.update(nextId, newF)
                                // print("  update [\(nx), \(ny)]  \(oldValue) -> \(newValue)")
                            }
                        }
                    }
                }
            }
            let targetCost = g[to.i][to.k]
            return (targetCost == unreacheable ? -1 : targetCost)
        }
        
        var ans = 0
        for i in 1..<tiles.count {
            let from = tiles[i-1]
            let to = tiles[i]
            let curCost = shortestPath(from, to)
            if curCost == -1 { return -1 }
            ans += curCost
        }
        // print(tiles)
       
        return ans
    }
}