func maxDistToClosest(seats []int) int {
    ans := 0
    begin := 0
    for i := 0; i < len(seats); i++ {
        if seats[i] != 0 {
            begin = i
            ans = i
            break
        }
    }
    
    for i := begin+1; i < len(seats); i++ {
        if seats[i] != 0 {
            mid := (begin+i)/2
            ans = max(ans, mid-begin)
            begin = i;
        }
    }
    ans = max(ans, len(seats) - begin - 1)
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
