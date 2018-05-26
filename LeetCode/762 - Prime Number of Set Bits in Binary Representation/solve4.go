func bitsSet(a int, counts *[]int) int {
    if a == 0 || a == 1 {
        return a
    }
    if (*counts)[a] == 0 {
        (*counts)[a] = a&1 + bitsSet(a>>1, counts)
    }
    
    return (*counts)[a]
}

func countPrimeSetBits(L int, R int) int {
    ans := 0
    prime := make([]bool, 21)
    for _, v := range []int{2, 3, 5, 7, 11, 13, 17, 19} {
        prime[v] = true
    }
    
    counts := make([]int, R+1)
    for a := L; a <= R; a++ {
        if prime[bitsSet(a, &counts)] {
            ans++
        }
    }
    return ans
}
