func licenseKeyFormatting(S string, K int) string {
    cnt := 0
    for _, c := range S {
        if c != '-' {
            cnt++
        }
    }
    
    left := cnt % K
    if left == 0 {
        left = K
    }
    ans := make([]rune, 0, cnt)
    
    for _, c := range S {        
        if c != '-' {
            if left == 0 {
                ans = append(ans, '-')
                left = K
            }
            ans = append(ans, unicode.ToUpper(c))
            left--
        }
    }
    
    return string(ans)
}
