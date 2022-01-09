class QueueNode {
    let val: Int
    var next: QueueNode?
    init(_ val: Int) { self.val = val }
}

class Queue {
    var head: QueueNode?
    var tail: QueueNode?
    var isEmpty: Bool { head == nil }

    func contains(_ val: Int) -> Bool {
        guard let head = head else { return false }
        var p = head
        if p.val == val { return true }
        while let next = p.next {
            p = next
            if p.val == val { return true }
        }
        return false
    }

    func front() -> Int {
        if let head = head {
            return head.val
        }
        return 0
    }

    func enqueue(_ val: Int) {
        var newNode = QueueNode(val)
        if let tail = tail {
            tail.next = newNode
            self.tail = newNode
        } else {
            head = newNode
            tail = newNode
        }
    }

    func dequeue() -> Int {
        if let head = head {
            var res = head.val
            if head === tail {
                tail = nil
            }
            self.head = head.next
            return res
        }
        return 0
    }

    var description: String { 
        guard let head = head else { return "[]" }
        var nums: [Int] = [head.val]
        var p = head
        while let next = p.next {
            p = next
            nums.append(p.val)
        }
        return "[\(nums.map { String($0) }.joined(separator: ","))]"
    }
}

var classesQ = Queue()
// var elementsQs = Array(repeating: Queue(), count: 4)
var elementsQs: [Queue] = []
for _ in 0..<4 { elementsQs.append(Queue()) }
let Q = Int(readLine()!)!
for _ in 0..<Q {
    let params = readLine()!.split(separator: " ")
    // print("Cmd: \(params)")
    switch params[0] {
        case "D":
            let k = classesQ.front()
            let m = elementsQs[k].dequeue()
            print("\(k+1) \(m)")
            if elementsQs[k].isEmpty {
                classesQ.dequeue()
            }
        case "E":
            let k = Int(params[1])!-1
            let m = Int(params[2])!
            elementsQs[k].enqueue(m)
            if !classesQ.contains(k) {
                classesQ.enqueue(k)
            }
        default:
            break
    }
    /*print("\(classesQ.description)")
    for i in 0..<elementsQs.count {
        print(" \(i) > \(elementsQs[i].description)")
    }*/
}