func addStrings(num1 string, num2 string) string {
    res := make([]int, 0)
    carry := 0
    count := max(len(num1), len(num2))
    for i, k := len(num1)-1, len(num2)-1; count > 0; count-- {
        sum := get_digit(num1, i) + get_digit(num2, k) + carry
        carry = sum / 10
        res = append(res, sum % 10)
        i--
        k--
    }
    if carry > 0 {
        res = append(res, carry)
    }
    
    ans := make([]byte, 0)
    for i := len(res)-1; i >= 0; i-- {
        ans = append(ans, byte(res[i] + int('0')))
    }
    return string(ans)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func get_digit(num string, pos int) int {
    if pos >= 0 {
        return int(num[pos]) - int('0')
    }
    return 0
}
