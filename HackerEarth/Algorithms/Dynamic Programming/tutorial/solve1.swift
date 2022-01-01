let T = Int(readLine()!)!

var A = Array(repeating: 0, count: 100001)
A[0] = 1
func solve(_ n: Int) -> Int {
    let cached = A[n]
    if cached != 0 { return cached }
    let res = (n * solve(n-1)) % 1000000007
    A[n] = res
    return res
}

for _ in 0..<T {
    let N = Int(readLine()!)!
    print(solve(N))
}
