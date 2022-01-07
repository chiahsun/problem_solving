func solve(_ nums: [Int], _ X: Int) -> Int {
    // print("\(nums) for \(X)")
    let N = nums.count
    var partialSum: [Int] = [0]
    var prev = 0
    // 1 2 3 4
    // 0 1 3 6 10
    for i in 0..<N {
        if nums[i] == X { return 1 }
        let cur = prev + nums[i]
        partialSum.append(cur)
        prev = cur
    }
    // print("partialSum: \(partialSum)")

    if partialSum.last! <= X { return N }

    func subArraySum(_ K: Int) -> Bool {
        // print("Check K: \(K)")
        for i in 0..<(N-K+1) { // K = N can be skiped ...
            if partialSum[i+K] - partialSum[i] > X {
                // print("psum[\(i+K)] - partialSum[\(i)] = \(partialSum[i+K] - partialSum[i])")
                return false
            }
        }
        return true
    }
    
    var i = 1
    var k = N
    while i < k {
        let mid = (i+k+1)/2
        let successful = subArraySum(mid)
        if successful {
            i = mid
        } else {
            k = mid-1
        }
    }

    return i
}
let X = readLine()!.split(separator: " ").map { Int($0)! }[1]
let A = readLine()!.split(separator: " ").map { Int($0)! }
print(solve(A, X))