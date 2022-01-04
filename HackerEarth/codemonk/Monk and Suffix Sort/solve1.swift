func solve(_ S: Substring, _ k: Int) -> Substring {
    var arr: [Substring] = []
    var si = S.startIndex
    while si != S.endIndex {
        arr.append(S[si...])
        si = S.index(after: si)
    }
    // print("arr: \(arr)")
    arr.sort()
    return arr[k-1]
}

while let line = readLine() {
    let params = line.split(separator: " ")
    let S = params[0]
    let k = Int(params[1])!
    // print("\(S) \(k)")
    print(solve(S, k))
}
