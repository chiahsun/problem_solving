func solve(_ m: Int, _ n: Int) -> [Int] {
    guard n >= 2 else { return [] }
    
    var res: [Int] = []
    if m <= 2 { res.append(2) }
    var m = m
    if m % 2 == 0 { m += 1 }
    for i in stride(from: max(3, m), through: n, by: 2) {
        var isPrime = true
        var d = 3
        while d*d <= i {
            if i % d == 0 {
                isPrime = false
                break
            }
            d += 2
        }
        if isPrime {
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
