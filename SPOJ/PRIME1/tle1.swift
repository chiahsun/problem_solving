func solve(_ m: Int, _ n: Int) -> [Int] {
    guard n >= 2 else { return [] }
    // let MAXN = 1000000000
    var s = Array(repeating: true, count: n+1)
    for i in 3..<s.count {
        if s[i] {
            for k in stride(from: i*i, to: s.count, by: i) {
                s[k] = false
            }
        }
        if i*i >= s.count-1 { break }
    }
    
    var res: [Int] = []
    if m <= 2 { res.append(2) }
    var m = m
    if m % 2 == 0 { m += 1 }
    for i in stride(from: max(3, m), through: min(n, s.count-1), by: 2) {
        if s[i] {
            res.append(i)
        }
    }
    return res
}

let T = Int(readLine()!)!

for i in 0..<T {
    let param = readLine()!.split(separator: " ")
    let res = solve(Int(param[0])!, Int(param[1])!)
    if i > 0 { print() }
    for i in res {
        print(i)
    }
}
