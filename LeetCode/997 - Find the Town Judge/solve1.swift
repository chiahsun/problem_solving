class Solution {
    func findJudge(_ n: Int, _ trust: [[Int]]) -> Int {
        var trustSomeone = Array(repeating: false, count: n+1)
        var trusted = Array(repeating: 0, count: n+1)
        for pair in trust {
            trusted[pair[1]] += 1
            trustSomeone[pair[0]] = true
        }
        for i in 1...n {
            if !trustSomeone[i] && trusted[i] == (n-1) {
                return i
            }
        }
        return -1
    }
}