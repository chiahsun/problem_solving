// A B C
// 1     1 0 0

//   1   0 1 0

// A B C
// 1     2 0 0
// 2

//   1   1 1 0
// 2

//   1   0 1 1
//     2

//     1 0 0 2
//     2

// A B C          A B C
// 1                  1
// 2     3 0 0        2  0 1 2
// 3                3

//   1            1
// 2     2 1 0        2  1 1 1
// 3                3

//   1            1
//     2 1 1 1      2    1 2 0
// 3                3

//     1            1
//     2 1 0 2      2    0 3 0
// 3                3

// 1 3 0
// 0 3 1
// 0 0 4


// A B C          A B C          A B C   A B C
// 1     4 0 0    1      2 1 1           0 0 4
// 2                  2
// 3                3
// 4              4

//   1   3 1 0   1       2 2 0
// 2                2
// 3                3
// 4             4

//   1   2 1 1      1   1 3 0
//     2            2
// 3                3
// 4             4

//     1 2 0 2
//     2
// 3
// 4

//     1 1 1 2
//     2
//   3
// 4

// f(n) = 2^n-1

// f(1) = 1 f(2) = 3 f(3) = 7 f(4) = 15 f(5) = 31 f(6) = 63

// v
//   v shift R 1
//     v shift R 2. So we check where 1 is, right shift by 1 or 2
// 0 1
//     2
//   3
//     4
//   5

// 5 = 3 + 1 + 1

// A B C         A B C
// 1                 1 (4)
// 2                 2
// 3               3

//     1 (3)     1     (5)
//     2             2
// 3               3

// 45 = 31 + 1 + 7 + 1 + 3 + 1 + 1

// A B C            A B C         A B C           A B C
//   1     (31)         1   (39)    1      (43)       1
//   2                  2           2               2
//   3                  3             3           3
//   4                4           4               4
//   5                5             5               5
// 6                    6             6               6
// 7                7             7               7
// 8                8             8               8

//   1    (32)          1   (40)    1      (44)
//   2                  2           2
//   3                  3         3
//   4             4              4
//   5                5             5
//     6                6              6
// 7               7              7
// 8               8              8

//            1                              1
//           ...                            ...
//            k                       k+1    k
//           ...                      ...   ....
//            n                ->      n
//          onePos
// pegs 0      1      2                1     ?(depends on m value)

func binarySearchLeqPos(_ nums: [Int], _ target: Int) -> Int {
    if target >= nums.last! { return nums.count-1 }
    if target <= nums.first! { return 0 }
    var i = 0, k = nums.count-1

    while i < k {
        let mid = (i+k+1)/2
        let midVal = nums[mid]
        if midVal > target {
            k = mid-1
        } else {
            i = mid
        }
    }
    return i
}

func solve(_ cnts: [Int], _ n: Int, _ m: Int, _ onePos: Int) -> [Int] {
    var m = m
    let k = binarySearchLeqPos(cnts, m)
    var res = [0, 0, 0]
    res[onePos] = n-k
    let kPos = (onePos + (k%2 == 1 ? 1 : 2)) % 3
    res[kPos] = k
    m -= cnts[k]
    if m == 0 {
        return res
    }
    let nextLargestPos = ((3 - kPos - onePos) % 3 + 3) % 3
    res[onePos] -= 1
    res[nextLargestPos] += 1
    m -= 1
    if m == 0 {
        return res
    }
    let smallerRes = solve(cnts, k, m, kPos)
    res[kPos] -= k
    return zip(res, smallerRes).map(+)
}

// 100 would overflow, so we just have a example here
var cnts = [0]
for _ in 0..<30 { cnts.append(2 * cnts.last! + 1) }
// print("cnts: \(cnts)")

while let line = readLine() {
    let params = line.split(separator: " ")
    let N = Int(params[0])!
    let M = Int(params[1])!
    if N == 0 && M == 0 { break }
    // print("\(N) \(M)")
    print(solve(cnts, N, M, 0).map { String($0) }.joined(separator: " "))
}