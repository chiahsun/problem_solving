func solve(_ arr: [Character]) -> Int {
    // let arr = arr.filter { $0 == "{" || $0 == "}" }
    var cntL = 0
    var totalL = 0
    let expectedL = arr.count/2
    var ans = 0
    for c in arr {
        if c == "{" {
            if totalL == expectedL {
                ans += 1
                cntL -= 1
            } else {
                cntL += 1
                totalL += 1
            }
        } else {
            if cntL == 0 {
                ans += 1
                cntL += 1
                totalL += 1
            } else {
                cntL -= 1
            }
        }
    }
    return ans
}

var casePos = 1
while case let line = readLine()!, line.first! != "-" {
    print("\(casePos). \(solve(Array(line)))")
    casePos += 1
}
