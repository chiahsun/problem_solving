func isPrime(a int) bool {
    if a == 2 || a == 3 || a == 5 {
        return true
    }
    if a == 1 || a % 2 == 0 || a % 3 == 0 || a % 5 == 0 {
        return false
    }
    
    for i := 3; i*i <= a; i += 2 {
        if a % i == 0 {
            return false
        }
    }
    
    return true
}

func bitsSet(a int) int {
    cnt := 0
    for a > 0 {
        if a & 0x1 != 0 {
            cnt++
        }
        a >>= 1
    }
    return cnt
}

func countPrimeSetBits(L int, R int) int {
    ans := 0
    for a := L; a <= R; a++ {
        if isPrime(bitsSet(a)) {
            ans++
        }
    }
    return ans
}
