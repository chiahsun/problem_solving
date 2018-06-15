func countSegments(s string) int {
    ans := 0
    ws := true
    
    for i := 0; i < len(s); i++ {
        if (ws && s[i] == ' ') || (!ws && s[i] != ' ') {
        } else {
            if ws {
                ans++
            }
            ws = !ws
        }
    }
    
    return ans
}
