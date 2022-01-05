func solve(_ nums: [Int]) -> Int {
    // print(nums)
    var m: [Int: Int] = [:]
    for a in nums { m[a, default: 0] += 1}
    var A: [(Int, Int)] = []
    for (a, cnt) in m {
        A.append((a, cnt))
    }
    A.sort(by: { a, b in
        a.1 < b.1
    })
    // print("A: \(A)")

    // (1,1) (2,2) (3,3)
    // (3,1) (2,2) (1,3)
    // (3,1) (1,3) (2,4) 
    var k = A.count-1
    while k > 0 {
        for i in 0..<k {
            if A[i].0 < A[k].0 {
                return A[k].1 - A[i].1
            }
        }
        k -= 1
    }

    return -1
}

let T = Int(readLine()!)!

for _ in 0..<T {
    let _ = readLine()!
    let nums = readLine()!.split(separator: " ").map { Int($0)! }
    print(solve(nums))
}