class Solution {    
    func allPathsSourceTarget(_ graph: [[Int]]) -> [[Int]] {
        var ans: [[Int]] = []
        var st: [[Int]] = [[0]]
        
        let N = graph.count
        while let curHistory = st.popLast() {
            for next in graph[curHistory.last!] {
                var nextHistory = curHistory
                nextHistory.append(next)
                if next == N-1 {
                    ans.append(nextHistory)
                } else {
                    st.append(nextHistory)   
                }
            }
        }
        return ans
    }
}