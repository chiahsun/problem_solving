func checkPerfectNumber(num int) bool {
    m := make(map[int]int)
    a := num
    divisor := 2
    for divisor*divisor <= a {
        if a % divisor == 0 {
            m[divisor]++
            a /= divisor
        } else {
            divisor++
        }
    }
    if a != 1 {
        m[a]++
    }
    
    return get_sum(m) == 2*num
}

func get_sum(m map[int]int) int {
    sum := 1
    for k, v := range m {
        total := 1
        cur := k
        for i := 0; i < v; i++ {
            total += cur
            cur *= k
        }
        sum *= total
    }
    return sum
}
