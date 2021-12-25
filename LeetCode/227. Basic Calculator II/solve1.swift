class Solution {
    func compute(_ operators: inout [Character], _ operands: inout [Int], _ done: Bool) {
        // print("\(operators) \(operands) \(done)")
        if let op = operators.last {
            switch op {
                case "*", "/":
                    let second = operands.removeLast()
                    let first = operands.removeLast()
                    operators.removeLast()
                    if op == "*" { operands.append(first * second) }
                    else         { operands.append(first / second) }
                default:
                    break
            }
        }
        if done || operators.count > 1 {
            while let op = operators.first {
                operators.removeFirst()
                let first = operands.removeFirst()
                let second = operands.removeFirst()
                if op == "+" { operands.insert(first + second, at: 0) }
                else         { operands.insert(first - second, at: 0) }
                if !done { break }
            }
        }
    }
    
    func appendNumIfExists(_ nums: inout String, _ operands: inout [Int]) -> Bool {
        if !nums.isEmpty {
            operands.append(Int(nums)!)
            nums = ""
            return true
        }
        return false
    }
    
    func calculate(_ s: String) -> Int {
        // *, /
        // +, -
        var s = s
        var operators: [Character] = [] 
        var operands: [Int] = []
        var nums = ""
        for c in s {
            // print("cur: \(first)")
            if c == " " { 
                if appendNumIfExists(&nums, &operands) {
                    compute(&operators, &operands, false)    
                }
            }
            else if c == "+" || c == "-" || c == "*" || c == "/" {
                if appendNumIfExists(&nums, &operands) {
                    compute(&operators, &operands, false)
                }
                operators.append(c)
            } else {
                nums.append(c)
            }
        }
        appendNumIfExists(&nums, &operands)
        compute(&operators, &operands, true)
        return operands.first!
    }
}