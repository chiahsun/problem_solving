func computeOrder(_ suffixes: [Int], _ s: [Character]) -> [Int] {
    let N = suffixes.count
    var order: [Int] = Array(repeating: 0, count: N)
    var groupId = 0
    for i in 1..<N {
        let cur = suffixes[i]
        if (s[cur] != s[suffixes[i-1]]) {
            groupId += 1
        } 
        order[cur] = groupId
    }
    return order
}

func computeOrder2(_ suffixes: [Int], _ s: [Character], _ oldOrder: [Int], _ sz: Int) -> [Int] {
    let N = suffixes.count
    var order: [Int] = Array(repeating: 0, count: N)
    var groupId = 0
    
    func getOrder(_ oldOrder: [Int], _ pos: Int, _ sz: Int) -> Int {
        if pos+sz < oldOrder.count { return oldOrder[pos+sz] }
        return -1
    }
    
    for i in 1..<N {
        let cur = suffixes[i]
        if (oldOrder[cur] != oldOrder[suffixes[i-1]]) || (getOrder(oldOrder, cur, sz) != getOrder(oldOrder, suffixes[i-1], sz)) {
            groupId += 1
        } 
        order[cur] = groupId
    }
    return order
}

func suffixSort(_ s: [Character]) -> [Int] {
    let N = s.count
    var suffixes = Array(0...(N-1)).sorted {
        s[$0] < s[$1]
    }
    var order = computeOrder(suffixes, s)
    
    var sz = 1
    while sz < N {
        suffixes.sort {
            if order[$0] != order[$1] {
                return order[$0] < order[$1] 
            }
            if $0+sz >= N { return true }
            if $1+sz >= N { return false }
            return order[$0+sz] < order[$1+sz] 
        }
        order = computeOrder2(suffixes, s, order, sz)
        sz *= 2
    }
    
    // print("suffixes: \(suffixes)")
    // print("order: \(order)")
    return suffixes
}



class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {
        guard needle.count > 0 else { return 0 }
        guard haystack.count >= needle.count else { return -1 }
        if haystack.hasPrefix(needle) { return 0 }
        
        var haystack = Array(haystack)
        let M = haystack.count
        let N = needle.count
        let suffixArray = suffixSort(haystack)
        
        var i = 0
        var k = M-1
        if String(haystack[suffixArray[i]...]) > needle && !String(haystack[suffixArray[i]...]).hasPrefix(needle) { return -1 }
        if String(haystack[suffixArray[k]...]) < needle { return -1 }

        // Find the greatest element that < needle
        while i < k {
            let mid = (i+k+1)/2
            let midVal = String(haystack[suffixArray[mid]...]) 

            // print("mid: \(mid) suffixArray[mid]: \(suffixArray[mid]) midVal: \(midVal)")
            if midVal >= needle {
                k = mid-1
            } else {
                i = mid
            }
        }
        if i == (M-1) { return -1 }
        let lo = i+1
        
        i = 0
        k = M-1
        // Find the least element that >= needle
        while i < k {
            let mid = (i+k)/2
            let midVal = String(haystack[suffixArray[mid]...]) 
            // print("mid: \(mid) suffixArray[mid]: \(suffixArray[mid]) midVal: \(midVal)")
            if midVal > needle && !midVal.hasPrefix(needle)  {
                k = mid
            } else {
                i = mid+1
            }
        }
        if i == 0 { return -1 }
        // print("i: \(i) -> \(String(haystack[suffixArray[i]...]))")
        let hi = (String(haystack[suffixArray[i]...]).hasPrefix(needle)) ? i : (i-1)

        // print("lo: \(lo) hi: \(hi)")
        if hi < lo { return -1 }
        return (lo...hi).map { suffixArray[$0] }.min()!
    }
}