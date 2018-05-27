import "unicode"

func letterRecur(a []byte) [][]byte {
    if len(a) == 0 {
        return [][]byte{a}
    }
    
    cur := []byte{}
    if unicode.IsNumber(rune(a[0])) {
        cur = []byte{a[0]}
    } else {
        cur = []byte{byte(unicode.ToLower(rune(a[0]))), byte(unicode.ToUpper(rune(a[0])))}
    }
    
    right := letterRecur(a[1:])
    res := [][]byte{}
    
    for _, prefix := range cur {
        for _, suffix := range right {        
            cur_wd := append([]byte{prefix}, suffix...)
            res = append(res, cur_wd)
        }
    }
    
    return res
}

func letterCasePermutation(S string) []string {
    lst := letterRecur([]byte(S))
    ans := []string{}
    
    for _, l := range lst {
        ans = append(ans, string(l))
    }
    return ans
}
