func square(_ a: Int) -> Int { a * a }

func solve(_ R: [Int], _ q: Int) -> Int {
    var q = q
    q = square(q)
    // print("R: \(R) q: \(q)")
    if q >= R.last! { return R.count }
    if q < R.first! { return 0 }
    var i = 0
    var k = R.count-1
    while i < k {
        let mid = (i+k+1)/2
        let midVal = R[mid]
        // print("mid: \(mid) midVal: \(midVal)")
        if midVal <= q {
            i = mid
        } else {
            k = mid-1
        }
    }
    
    return i+1
}

let N = Int(readLine()!)!
var R: [Int] = []
for _ in 0..<N {
    let params = readLine()!.split(separator: " ").map { Int($0)! }
    R.append(square(params[0]) + square(params[1]))
}
R.sort()

let Q = Int(readLine()!)!
for _ in 0..<Q {
    let q = Int(readLine()!)!
    if q >= 1500000000 { print(R.count) } // 1.5 * 1E9 > sqrt{2} * 1E9 
    else {
        print(solve(R, q))
    }
}