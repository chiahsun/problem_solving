// 1 (lose)

// 2 (win)
// 1: 2-1=1 other lose = win


// 3 (lose)
// 1: 3-1=2 other win = lose

// 4 (win)
// 1: 4-1=3 other lose = win

// 5 (lose)
// 1: 5-1=4 other win = lose

// 6 (win)
// 1: 6-1=5 other lose = win

// 7 (lose)
// 1: 7-1=6 other win = lose

// 8 (win)
// 1: 8-1=7 other lose = win

// 9 (lose)
// 1: 9-1 = 8 other win = lose
// 3: 9-3 = 6 other win = lose

class Solution {
    func divisorGame(_ n: Int) -> Bool {
        let unknown = 0
        let win = 1
        let lose = 2
        var A = Array(repeating: 0, count: n+1)
        A[1] = lose
        
        func nextResult(_ x: Int) -> Int { 3 - x }
        
        func search(_ x: Int) -> Int {
            if A[x] != unknown { return A[x] }
            var res = nextResult(search(x-1))
            var d = 2
            while res != win, d*d <= x {
                if x % d == 0 {
                    res = nextResult(search(x-d))                    
                    if res != win {
                        let another = x/d
                        if another != d {
                            res = nextResult(search(x-another))
                        }
                    }
                }
                d += 1
            }
            A[x] = res
            return res
        }
        let res = search(n)
        return res == win
    }
}