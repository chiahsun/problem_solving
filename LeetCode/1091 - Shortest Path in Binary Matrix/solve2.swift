class PQ {
    var A: [Int] = []
    
    var keyToPos: [Int]
    var values: [Int]
    
    init(_ N: Int) { 
        keyToPos = Array(repeating: -1, count: N)
        values = Array(repeating: 0, count: N)
    }
    
    private func add(_ key: Int, _ value: Int) {
        let pos = A.count
        A.append(key)
        values[key] = value
        keyToPos[key] = pos
        swimUp(pos)
    }
    
    func update(_ key: Int, _ value: Int) {
        if keyToPos[key] == -1 {
            add(key, value)
            return
        }
        let oldValue = values[key]
        guard oldValue != value else { return }
        let pos = keyToPos[key]
        if value < oldValue { swimUp(pos) }
        else                { swimDown(pos) }
    }
    
    private func lessThanByPos(_ i: Int, _ k: Int) -> Bool {
        values[A[i]] < values[A[k]]
    }
    
    //     0
    //  1     2
    // 3 4
    private func swimUp(_ pos: Int) {
        var pos = pos
        while pos > 0, case let parent = (pos-1)/2, lessThanByPos(pos, parent) {
            swapAtPos(pos, parent)
        }
    }
    
    private func swimDown(_ pos: Int) {
        var pos = pos
        let N = A.count
        while case let leftPos = 2*pos+1, leftPos < N {
            var minPos = pos
            if lessThanByPos(leftPos, pos) { minPos = leftPos }
            if case let rightPos = 2*pos+2, rightPos < N, lessThanByPos(rightPos, pos) { minPos = rightPos }
            if minPos != pos { swapAtPos(pos, minPos); pos = minPos }
            else             { break }
        }
    }
    
    private func swapAtPos(_ i: Int, _ k: Int) {
        guard i != k else { return }
        keyToPos.swapAt(A[i], A[k])
        A.swapAt(i, k)
    }
    
    func popMin() -> (Int, Int)? {
        guard !A.isEmpty else { return nil }
        let minKey = A[0]
        let minValue = getValue(minKey)
        
        swapAtPos(0, A.count-1)
        A.removeLast()
        keyToPos[minKey] = -1
        values[minKey] = 0
        
        if !A.isEmpty { swimDown(0) }
        return (minKey, minValue)
    }
    
    func getValue(_ key: Int) -> Int {
        return values[key]
    }
    
    func printPQ() {
        print("  A: ", A.map { String($0) }.joined(separator: " "))
    }
}

class Solution {
    func shortestPathBinaryMatrix(_ grid: [[Int]]) -> Int {
        guard grid[0][0] == 0 else { return -1 }
        
        let N = grid.count
        
        var pq = PQ(N * N)
        var ids = grid
        var idToPos: [(Int, Int)] = []
        for i in 0..<N {
            for k in 0..<N {
                ids[i][k] = idToPos.count
                idToPos.append((i, k))
            }
        }
        var closed = Array(repeating: false, count: idToPos.count)
        
        var costs: [[Int]] = Array(repeating: Array(repeating: idToPos.count+10, count: N), count: N)
        
        let dx: [Int] = [1, 1,  1, 0,  0, -1, -1, -1]
        let dy: [Int] = [1, 0, -1, 1, -1,  1,  0, -1]

        costs[0][0] = 1
        pq.update(0, 1)
        

        while let (cur, curCost) = pq.popMin() {
            let (curx, cury) = idToPos[cur]
            // print("[\(curx), \(cury)] -> \(curCost)")
            closed[ids[curx][cury]] = true
            
            if curx == N-1 && cury == N-1 { return curCost }
            
            for i in 0..<dx.count {
                let nx = curx + dx[i]
                let ny = cury + dy[i]
                if nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == 0 && !closed[ids[nx][ny]] {
                    let oldValue = costs[nx][ny]
                    let newValue = curCost + 1
                    if newValue < oldValue {
                        costs[nx][ny] = newValue
                        pq.update(ids[nx][ny], newValue)
                    }
                }
            }
        }
        
        return -1
    }
}