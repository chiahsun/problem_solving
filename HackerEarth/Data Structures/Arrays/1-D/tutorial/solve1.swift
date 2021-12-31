let N = Int(readLine()!)!
var arr = Array(repeating: 0, count: N)
for i in 0..<N { arr[i] = Int(readLine()!)! }

var ans = solve(arr)
ans.forEach { print($0) }

func solve(_ arr: [Int]) -> [Int] {
    var res: [Int] = []
    for i in stride(from: arr.count-1, through: 0, by: -1) {
        res.append(arr[i])
    }
    return res
}