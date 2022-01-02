// 25114
// 2|5|1|1|4
// 2|5|1|14
// 2|5|11|4
// 25|1|1|4
// 25|1|14
// 25|11|4

func solve(_ arr: [Int]) -> Int {
    let N = arr.count
    var dp = Array(repeating: 0, count: N+1)
    dp[0] = 1 // Add dummy head
    dp[1] = 1
    for i in 1..<N {
        if arr[i] != 0 { dp[i+1] = dp[i] }
        if arr[i-1] == 1 { dp[i+1] += dp[i-1] }
        else if arr[i-1] == 2 && arr[i] <= 6 { dp[i+1] += dp[i-1] }
    }
    return dp.last!
}

while case let line = readLine()!, line != "0" {
    var arr: [Int] = []
    for c in line {
        arr.append(Int(String(c))!)
    }
    print(solve(arr))
}
