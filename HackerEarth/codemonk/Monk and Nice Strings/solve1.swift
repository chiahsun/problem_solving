let N = Int(readLine()!)!
var arr: [String] = []
for _ in 0..<N {
    let target = readLine()!
    arr.append(target)
    arr.sort()
    // print(arr)
    for i in 0..<arr.count {
        if arr[i] == target {
            print(i)
            break
        }
    }
}