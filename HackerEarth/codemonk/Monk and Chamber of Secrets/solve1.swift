class QueueNode<T> {
    var prev: QueueNode<T>? = nil
    var next: QueueNode<T>? = nil
    var val: T
    init(_ val: T) { self.val = val }
}

class Queue<T> {
    var head: QueueNode<T>? = nil
    var tail: QueueNode<T>? = nil
    var count = 0

    func append(_ val: T) -> QueueNode<T> {
        let newNode = QueueNode(val)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            newNode.prev = tail
            tail = newNode
        }

        count += 1
        return newNode
    }

    func pop() -> T? {
        if let head = head {
            return remove(head)
        }
        return nil
    }

    func remove(_ node: QueueNode<T>) -> T {
        let res = node.val
        if node === head {
            head = node.next
            if let head = head {
                head.prev = nil
            } else {
                tail = nil
            }
        } else {
            if let next = node.next {
                next.prev = node.prev
            } else {
                tail = node.prev
            }
            if let prev = node.prev {
                prev.next = node.next
            }
        }
        count -= 1
        return res
    }
}


func solve(_ nums: [Int], _ X: Int) -> [Int] {
    var q = Queue<(Int, Int)>()
    for i in 0..<nums.count {
        q.append((nums[i], i))
    }
    var ans: [Int] = []
    for _ in 0..<X {
        var maxVal = -1
        var maxNode: QueueNode<(Int, Int)>? = nil
        let curQueueSize = q.count
        for _ in 0..<min(X, curQueueSize) {
            if let cur = q.pop() {
                let nextVal = (cur.0 > 0) ? (cur.0-1) : 0
                if cur.0 > maxVal {
                    maxVal = cur.0
                    maxNode = q.append((nextVal, cur.1))
                } else {
                    q.append((nextVal, cur.1))
                }
            }
        }
        if let maxNode = maxNode {
            ans.append(maxNode.val.1+1)
            q.remove(maxNode)
        }
    }

    return ans
}

let params = readLine()!.split(separator: " ").map { Int($0)! }
let X = params[1]
let nums = readLine()!.split(separator: " ").map { Int($0)! }

print(solve(nums, X).map { String($0) }.joined(separator: " "))