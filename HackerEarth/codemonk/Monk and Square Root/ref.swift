// 0: 0 % 6 = 0
// 1: 1 % 6 = 1
// 2: 4 % 6 = 4
// 3: 9 % 6 = 3     ----- mid
// 4: 16 % 6 = 4
// 5: 25 % 6 = 1
// 6: 36 % 6 = 0
// 49 % 6 = 1 
// 64 % 6 = 4
// 81 % 6 = 3
// 100 % 6 = 4
// 121 % 6 = 1
// 144 % 6 = 0

// 2
// 6+2 = 8
// 12+2 = 14
// 18+2 = 20
// 24+2 = 26
// 30+2 = 32

// 0: 0 % 5 = 0
// 1: 1 % 5 = 1
// 2: 4 % 5 = 4    ------ mid
// 3: 9 % 5 = 4    ------ mid
// 4: 16 % 5 = 1
// 5: 25 % 5 = 0
// 36 % 5 = 1

// [14, 7^2]
// 17, 24, 31, 36, 43,  
// 0 % 14 = 0
// 1 % 14 = 1
// 4 % 14 = 4
// 9 % 14 = 9
// 16 % 14 = 2
// 25 % 14 = 11
// 36 % 14 = 8
// 49 % 14 = 7   ----------- mid
// 64 % 14 = 8
// 81 % 14 = 11
// 100 % 14 = 2
// 121 % 14 = 9
// 144 % 14 = 4
// 169 % 14 = 1

// 0 % 30 = 0
// ...
// 25 % 30 = 25 ---^ No need to compute
// 36 % 30 = 6
// 49 % 30 = 19
// 64 % 30 = 24
// 81 % 30 = 21
// 100 % 30 = 10
// ...
// 196 % 30 = 16
// 225 % 30 = 15 -- mid
// 256 % 30 = 16

// Show that (N^2 mod M) = ((M-N)^2 % M)
// So we only to test math.ceil(M.count) number

// If N^2 is a square number and N^2 < M, then answer is N.

// Or we can test if kM+N is a square number??

func gcd(_ a: Int, _ b: Int) -> Int {
    var a = a, b = b
    while b > 0 {
        (a, b) = (b, a % b)
    }
    return a
}

func fact(_ a: Int) -> [Int: Int] {
    var a = a
    var d = 2
    var m: [Int: Int] = [:]
    while d*d <= a {
        if a % d == 0 {
            while a % d == 0 {
                m[d, default: 0] += 1
                a /= d
            }
        }
        d += 1
    }
    m[a, default: 0] += 1
    return m
}

func isSquareNumer(_ a: Int) -> Bool {
    let m = fact(a)
    for (_, cnt) in m where cnt % 2 == 1 {
        return false 
    }
    return true
}

func getLeastSquareGeq(_ a: Int) -> Int {
    var m = fact(a)
    for (d, cnt) in m where cnt % 2 == 1 {
        m[d]! += 1
    }
    var res = 1
    for (d, cnt) in m {
        for _ in 0..<cnt {
            res *= d
        }
    }
    return res
}

func solve(_ N: Int, _ M: Int) -> Int {
    if N == 0 { return 0 }
    if isSquareNumer(N) { return N }

    let d = getLeastSquareGeq(gcd(N, M)) // Can be optimized to the least square number that's multiple of d
    for i in stride(from: 0, through: M, by: d) {
        if i*i % M == N {
            return i
        }
    }
    return -1
}

let T = Int(readLine()!)!
for _ in 0..<T {
    let params = readLine()!.split(separator: " ").map { Int($0)! }
    let N = params[0], M = params[1]
    print(solve(N, M))
}
