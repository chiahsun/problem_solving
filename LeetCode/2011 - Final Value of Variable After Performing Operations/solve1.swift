class Solution {
    func finalValueAfterOperations(_ operations: [String]) -> Int {
        var ans = 0
        for cmd in operations {
            switch cmd {
                case "++X", "X++":
                    ans += 1
                case "--X", "X--":
                    ans -= 1
                default:
                    break
            }
        }
        return ans
    }
}