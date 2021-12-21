class Solution {
    func processQueries(_ queries: [Int], _ m: Int) -> [Int] {
        var A: [(Int, Int)] = [(1, m)]
        var ans: [Int] = []
        for query in queries {
            var done = false
            var pos = 0
            var nextA: [(Int, Int)] = []
            for (a, b) in A {
                if !done {
                    if a <= query && query <= b {
                        nextA = [(query, query)] + nextA
                        ans.append(pos + (query-a))
                        if a < query {
                            nextA.append((a, query-1))
                        }
                        if b > query {
                            nextA.append((query+1,b))
                        }
                        done = true
                    } else {
                        nextA.append((a, b))
                    }
                    pos += (b-a+1)
                } else {
                    nextA.append((a, b))
                }
                A = nextA
            }
        }
        return ans
    }
}