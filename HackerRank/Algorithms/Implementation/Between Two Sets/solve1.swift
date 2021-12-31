import Foundation

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

// 2 4 -> 4
// 16 32 96 -> 16
// 16 = 4 x (2 x 2)    (1 + 2)

// 4 6 9 -> 36
// 216
// 216 = 36 x(2 x 3)  (1+1)x(1+2)

func gcd(_ a: Int, _ b: Int) -> Int {
    var a = a
    var b = b
    while b > 0 {
        (a, b) = (b, a % b)
    }
    return a
}

func gcd(arr: [Int]) -> Int {
    var res = arr[0]
    arr.forEach { res = gcd(res, $0) }
    return res
}

func lcm(arr: [Int]) -> Int {
    var res = arr[0]
    for i in 1..<arr.count {
        let cur = arr[i]
        res *= cur/gcd(cur, res)
    }
    return res
}

func factorize(_ a: Int) -> [Int: Int] {
    var m: [Int: Int] = [:]
    var a = a
    while a > 1 && a % 2 == 0 { a /= 2; m[2, default: 0] += 1 }
    var p = 3
    
    while a > 1, p * p <= a {
        while a % p == 0 { a /= p; m[p, default: 0] += 1 }
        p += 2
    }
    if a > 1 { m[a] = 1 }
    
    return m
}

func getTotalX(a: [Int], b: [Int]) -> Int {
    // Write your code here
    let minFactor = lcm(arr: a)
    let maxFactor = gcd(arr: b)
    if maxFactor % minFactor != 0 { return 0 }
    
    let factors = factorize(maxFactor/minFactor)
    var ans = 1
    for (_, cnt) in factors {
        ans *= (cnt+1)
    }
    return ans
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let firstMultipleInputTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }
let firstMultipleInput = firstMultipleInputTemp.split(separator: " ").map{ String($0) }

guard let n = Int(firstMultipleInput[0])
else { fatalError("Bad input") }

guard let m = Int(firstMultipleInput[1])
else { fatalError("Bad input") }

guard let arrTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let arr: [Int] = arrTemp.split(separator: " ").map {
    if let arrItem = Int($0) {
        return arrItem
    } else { fatalError("Bad input") }
}

guard arr.count == n else { fatalError("Bad input") }

guard let brrTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let brr: [Int] = brrTemp.split(separator: " ").map {
    if let brrItem = Int($0) {
        return brrItem
    } else { fatalError("Bad input") }
}

guard brr.count == m else { fatalError("Bad input") }

let total = getTotalX(a: arr, b: brr)

fileHandle.write(String(total).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)
