func appendRange(_ A: inout [(Int, Int)], _ next: (Int, Int)) {
    let (a, b) = next
    if let last = A.last, last.0 != 0 && last.1+1 == a {
        A[A.count-1].1 = b
    } else {
        A.append((a, b))
    }
}

class Solution {
    func processQueries(_ queries: [Int], _ m: Int) -> [Int] {
        var A: [(Int, Int)] = [(1, m)]
        var nextA: [(Int, Int)] = []
        var ans: [Int] = []
        for query in queries {
            // print("Query: \(query)")
            var done = false
            var pos = 0
            nextA = [(0, 0)]
            for (a, b) in A {
                // print("  > (\(a), \(b))")
                if !done {
                    if a <= query && query <= b {
                        nextA[0] = (query, query)
                        ans.append(pos + (query-a))
                        if a < query {
                            appendRange(&nextA, (a, query-1))
                        }
                        if b > query {
                            appendRange(&nextA, (query+1,b))
                        }
                        done = true
                    } else {
                        appendRange(&nextA, (a, b))
                    }
                    pos += (b-a+1)
                } else {
                    appendRange(&nextA, (a, b))
                }
                // print("  > nextA: \(nextA)")
            }
            A = nextA
            // print("A: \(A)")
        }
        return ans
    }
}