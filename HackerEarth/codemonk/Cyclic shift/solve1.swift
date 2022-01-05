// 10101
// 01011
// 10110
// 01101
// 11010
// [2,-1,1,-1]

// 010101
// 101010
// 010101
// 101010
// [1,-1,1,-1,1,-1]

func gcd(_ a: Int, _ b: Int) -> Int {
    var a = a
    var b = b
    while b > 0 {
        (a, b) = (b, a % b)
    }
    return a
}

func findCycleCount(_ A: [Int], _ N: Int) -> Int {
    let M = A.count
    // print("M: \(M)")
    guard M > 1 else { return 1 }
    // [1,0,1,0,1,0,1,0,1,0]
    // [1,-1,1,-1,1,-1,1,-1,1,-1]
    //  1   1  1   1   1
    // TODO: this
    // [1,-1,1,-1,1,-1,1,-1,1,-2]
    var cnt = 1
    var q = Array(1..<M).filter { A[$0] == A[0] && gcd(M, $0) > 1 }
    var qNext: [Int] = []
    while !q.isEmpty {
        for pos in q {
            let cur = pos+cnt
            // print("pos: \(pos) at cnt: \(cnt) > \(gcd(M, pos))")
            if cur < M && A[cur] == A[cnt] && pos > cnt && gcd(M, pos) > cnt {
                qNext.append(pos)
            }
        }
        q = qNext
        qNext.removeAll()
        cnt += 1
        // print("In q: \(q) cnt: \(cnt)")
        if M % cnt == 0 && q.count+1 >= M / cnt {
            var ok = true
            let s = Set<Int>(q)
            for i in stride(from: cnt, to: M, by: cnt) {
                if !s.contains(i) {
                    ok = false
                    break
                }
            }
            if ok {
                return (0..<cnt).map { abs(A[$0]) }.reduce(0, +)
            }
        }
    }
    return N
}

func findMaxPosOffset(_ A: [Int]) -> Int {
    let N = A.count
    // print("A: \(A)")
    let S = Array(0..<N).sorted(by: { A[$0] > A[$1] })
    // print("S: \(S)")
    var order = Array(repeating: 0, count: N)
    var id = 0
    for i in 1..<N {
        if A[S[i]] != A[S[i-1]] { id += 1 }      
        order[S[i]] = id
    }
    // print("Order: \(order)")
    var cnt = 1
    while cnt < N {
        let S = Array(0..<N).sorted(by: { 
            if order[$0] != order[$1] { return order[$0] < order[$1] }
            return order[($0+cnt)%N] < order[($1+cnt)%N]
        })
        // print("S: \(S) with cnt: \(cnt)")
        var orderNext = Array(repeating: 0, count: N)
        var id = 0
        var cnt0 = 1
        for i in 1..<N {
            if order[S[i]] != order[S[i-1]] || order[(S[i]+cnt)%N] != order[(S[i-1]+cnt)%N] { 
                id += 1 
                // print("Check at \(S[i]): \(A[S[i]]) with at \(S[i-1]): \(A[S[i-1]])  id: \(id)")
            }
            if id == 0 { cnt0 += 1 }
            orderNext[S[i]] = id
        }
        order = orderNext
        if cnt0 == 1 { break }
        // print("Order: \(order)")
        cnt *= 2
    }
    // print("At end cnt: \(cnt)")
    var maxPosOffset = 0
    for i in 0..<N {
        if order[i] == 0 { break }
        maxPosOffset += abs(A[i])
    }

    return maxPosOffset
}

func findMaxPosOffsetSlow(_ A: [Int], _ cycleCount: Int) -> Int {
    let M = A.count
    var maxPos = 0
    for i in stride(from: 2, through: cycleCount, by: 2) {
        var ok = false
        for k in 0..<M {
            let cur = A[(i+k)%M]
            let prev = A[(maxPos+k)%M]
            if cur > prev { ok = true; break }
            else if cur < prev { ok = false; break }
        }
        if ok { 
            maxPos = i 
        }
    }
    var maxPosOffset = 0
    for i in 0..<maxPos {
        maxPosOffset += abs(A[i])
    }
    return maxPosOffset
}

func solve(_ arr: [Character], _ K: Int) -> Int {
    var cur = 0
    var A: [Int] = []
    var startPos = 0
    let N = arr.count
    // 00000
    // 01101
    // 10101
    // 00101
    // 10001
    if arr.last! == "1" {
        while startPos < N, arr[startPos] == "1" {
            startPos += 1
        }
        if startPos == N { startPos = 0 }
    }
    while startPos < N, arr[startPos] == "0" {
        startPos += 1
    }
    if startPos == N { startPos = 0 }
    for i in 0..<N {
        let c = arr[(i+startPos)%N]
        if cur == 0 { 
            cur = (c == "1") ? 1 : -1
        } else if cur > 0 {
            if c == "0" { A.append(cur); cur = -1 }
            else        { cur += 1 }
        } else {
            if c == "1" { A.append(cur); cur = 1 }
            else        { cur -= 1 }
        }
    }
    A.append(cur)
    // print("A: \(A)")

    
    let cycleCount = findCycleCount(A, N)
    // print("cycleCount: \(cycleCount)")
    /* // O(N^2) too slow to find max pos offset
    */

    // findMaxPosOffset([2,-3,2,-3,3])
    // findMaxPosOffset([2,-3,2,-3,2,-3])
    var maxPosOffset = 0
    if cycleCount <= 1000 {
        maxPosOffset = findMaxPosOffsetSlow(A, cycleCount)
    } else {
        maxPosOffset = findMaxPosOffset(A)
    }

    var ans = startPos + maxPosOffset
    // print("startPos: \(startPos) maxPosOffset: \(maxPosOffset)")

    ans += cycleCount * (K-1)
    return ans
}

let T = Int(readLine()!)!
for _ in 0..<T {
    let params = readLine()!.split(separator: " ")
    // let N = Int(params[0])!
    let K = Int(params[1])!
    let A = Array(readLine()!)
    // print("\(N) \(K) \(A)")
    print(solve(A, K))
}
