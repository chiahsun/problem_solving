let params = readLine()!.split(separator: " ")
let N = Int(params[0])!
let K = Int(params[1])!

var A = Array(repeating: 0, count: N)
A[0] = 1
A[1] = 1
// 0 1 2 3 4 
// 1
//   1 2 
//       3
//         5
for i in 2..<N {
    A[i] = (2 * A[i-1]) - (i-K-1 >= 0 ? A[i-K-1] : 0)
    A[i] %= 1000000007
    // TLE
    /*for k in stride(from: i-1, through: max(0, i-K), by: -1) {
        A[i] += A[k]
        A[i] %= 1000000007
    }*/
}
print(A[N-1])