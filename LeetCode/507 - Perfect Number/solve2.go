func checkPerfectNumber(num int) bool {
    
    next_perfect_number := perfect_number_seq()
    N := int64(num)
    for perfect_number := next_perfect_number(); N >= perfect_number; perfect_number = next_perfect_number() {
        // fmt.Println("Next prefect number: ", perfect_number)
        if N == perfect_number {
            return true
        }
    }
    return false
}

func perfect_number_seq() func() int64 {
    var a int64 = 2
    return func() int64 {
        for a <= 100000000 {
            var old_a int64 = a
            a *= 2
            var b int64 = (a-1)
            if is_prime(b) {
                return old_a * b
            }
        }
        return a
    }
}

func is_prime(a int64) bool {
    var p int64 = 2
    for p*p <= a {
        if a % p == 0 {
            return false
        }
        p++
    }
    return true
}
