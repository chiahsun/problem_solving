func countSegments(s string) int {
    ans := 0
    ws := true
    if len(s) > 0 && s[0] != ' ' {
        ws = false
        ans++
    }
    
    for i := 1; i < len(s); i++ {
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
