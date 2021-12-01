
class MinStack {
    
    var values: [Int]
    var mins: [Int]

    init() {
        self.values = []
        self.mins = []
    }
    
    func push(_ val: Int) {
        values.append(val)
        mins.append(min(mins.last ?? val, val))
    }
    
    func pop() {
        values.removeLast()
        mins.removeLast()
    }
    
    func top() -> Int {
        values.last ?? 0
    }
    
    func getMin() -> Int {
        mins.last ?? 0
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack()
 * obj.push(val)
 * obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Int = obj.getMin()
 */