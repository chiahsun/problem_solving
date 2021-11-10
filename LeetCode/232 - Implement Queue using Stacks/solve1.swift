
class MyQueue {
    var pushq: [Int] = []
    var popq: [Int] = []
    
    init() {
    }
    
    func move() {
        if popq.isEmpty {
           while !pushq.isEmpty {
               popq.append(pushq.removeLast())
           } 
        }     
    }
    
    func push(_ x: Int) {
        pushq.append(x)
    }
    
    func pop() -> Int {
        move()
        return popq.removeLast()
    }
    
    func peek() -> Int {
        move()
        return popq.last ?? -1
    }
    
    func empty() -> Bool {
        return pushq.isEmpty && popq.isEmpty
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue()
 * obj.push(x)
 * let ret_2: Int = obj.pop()
 * let ret_3: Int = obj.peek()
 * let ret_4: Bool = obj.empty()
 */