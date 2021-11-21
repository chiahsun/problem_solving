
class MyHashMap {
    var A: [[(Int, Int)]]
    
    init() {
        A = Array(repeating: [], count: 10)
    }
    
    func resize() {
        var data: [(Int, Int)] = []
        for i in 0..<A.count {
            for k in 0..<A[i].count {
                data.append(A[i][k])
            }
        }
        
        let newSize = A.count * 4
        self.A = Array(repeating: [], count: newSize)
        for d in data {
               put(d.0, d.1)
        }
    }
    
    func put(_ key: Int, _ value: Int) {
        let pos = key%A.count
        for i in 0..<A[pos].count {
            if A[pos][i].0 == key {
                A[pos][i].1 = value
                return
            }
        }
        A[pos].append((key, value))
        if A[pos].count > 15 {
            resize()
        }
    }
    
    func get(_ key: Int) -> Int {
        let pos = key%A.count
        for i in 0..<A[pos].count {
            if A[pos][i].0 == key {
                return A[pos][i].1
            }
        }
        return -1
    }
    
    func remove(_ key: Int) {
        let pos = key%A.count
        for i in 0..<A[pos].count {
            if A[pos][i].0 == key {
                (A[pos][i], A[pos][A[pos].count-1]) = (A[pos][A[pos].count-1], A[pos][i])
                A[pos].removeLast()
                return
            }
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap()
 * obj.put(key, value)
 * let ret_2: Int = obj.get(key)
 * obj.remove(key)
 */