class PQ {
    var A: [Int] = []
    
    var keyPos: [Int]
    var values: [Int]
    
    init(_ N: Int) { 
        keyPos = Array(repeating: -1, count: N)
        values = Array(repeating: Int.max, count: N)
    }
    
    func getValue(_ key: Int) -> Int {
        return values[key]
    }
    
    func update(_ key: Int, _ value: Int) { 
        if keyPos[key] == -1 {
            values[key] = value
            let newPos = A.count
            keyPos[key] = newPos
            A.append(key)
            swimUp(newPos)
            return
        }
        
        let oldValue = values[key]
        values[key] = value
        if value < oldValue {
            swimUp(keyPos[key])
        } else if value > oldValue {
            swimDown(keyPos[key])   
        }
    }
    
    //     0
    //  1     2
    // 3 4
    func swimUp(_ pos: Int) {
        var pos = pos
        while pos > 0, case let parentPos = (pos-1)/2 {
            if lessThanByPos(pos, parentPos) {
                swapByPos(pos, parentPos)
                pos = parentPos
            } else {
                break
            }
        }
    }
    
    func swimDown(_ pos: Int) {
        var pos = pos
        while case let leftPos = 2*pos+1, leftPos < A.count {
            var minPos = pos
            if lessThanByPos(leftPos, pos) { minPos = leftPos }
            if case let rightPos = 2*pos+2, rightPos < A.count, lessThanByPos(rightPos, minPos) { minPos = rightPos }
            if minPos != pos {
                swapByPos(minPos, pos)
                pos = minPos
            } else {
                break
            }
        }
    }
    
    private func lessThanByPos(_ i: Int, _ k: Int) -> Bool {
        return (i == k) ? false : values[A[i]] < values[A[k]]
    }
    
    private func swapByPos(_ i: Int, _ k: Int) {
        guard i != k else { return }
        keyPos.swapAt(A[i], A[k])
        A.swapAt(i, k)
    }
    
    func popMin() -> (Int, Int)? {
        if A.isEmpty { return nil }
        
        let minKey = A[0]
        let minValue = values[minKey]
        
        swapByPos(0, A.count-1)
        A.removeLast()
        keyPos[minKey] = -1
        
        swimDown(0)
        
        return (minKey, minValue)
    }
}

struct Edge {
    let to: Int
    let cost: Int
}

class Solution {
    func networkDelayTime(_ times: [[Int]], _ n: Int, _ k: Int) -> Int {
        var pq = PQ(n)
        
        var adj: [[Edge]] = Array(repeating: [], count: n)
        var source = k-1
        for time in times {
            adj[time[0]-1].append(Edge(to: time[1]-1, cost: time[2]))
        }
        pq.update(source, 0)
        
        var confirmed = Array(repeating: false, count: n)
        var unvisited = n
        var ans = 0
        while let (cur, curCost) = pq.popMin() {
            confirmed[cur] = true
            ans = max(ans, curCost)
            unvisited -= 1
            if unvisited == 0 { break }
            for e in adj[cur] where !confirmed[e.to] {
                if case let newValue = curCost + e.cost, newValue < pq.getValue(e.to) {
                    pq.update(e.to, newValue)
                }
            }
        }
        
        return unvisited > 0 ? -1 : ans
    }
}