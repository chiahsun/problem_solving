class Solution {
    func backtracking(_ cur: inout [Character], _ enqueued: Int, _ todo: Int, _ ans: inout [String]) {
        if enqueued == 0 && todo == 0 {
            ans.append(String(cur))
            return
        }
        if todo > 0 {
            cur.append("(")
            backtracking(&cur, enqueued+1, todo-1, &ans)
            cur.removeLast()
        }
        if enqueued > 0 {
            cur.append(")")
            backtracking(&cur, enqueued-1, todo, &ans)
            cur.removeLast()
        }
    }
    
    func generateParenthesis(_ n: Int) -> [String] {
        var cur: [Character] = []
        var ans: [String] = []
        backtracking(&cur, 0, n, &ans)
        return ans.sorted()
    }
}