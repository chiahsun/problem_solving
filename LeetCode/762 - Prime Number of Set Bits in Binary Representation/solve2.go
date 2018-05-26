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
    // 20
    prime := []bool{false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false}
    for a := L; a <= R; a++ {
        if prime[bitsSet(a)] {
            ans++
        }
    }
    return ans
}
