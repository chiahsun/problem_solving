func largeGroupPositions(S string) [][]int {
    ans := make([][]int, 0)
    begin_last, last := 0, S[0]
    for i := 1; i < len(S)+1; i++ {
        if i == len(S) || S[i] != last {
            if i - begin_last >= 3 {
                ans = append(ans, []int{begin_last, i-1})
            } 
            if i < len(S) {
                begin_last, last = i, S[i]
            }
        }
    }
    return ans
}
