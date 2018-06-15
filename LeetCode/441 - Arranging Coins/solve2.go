func arrangeCoins(n int) int {
    lo, hi := 0, 65535
    if n >= get_sum(hi)  {
        return hi
    }
    
    ans := 0
    for lo <= hi {
        mid := lo + (hi-lo)/2
        
        switch {
        case n < get_sum(mid):
            hi = mid-1
        case n == get_sum(mid):
            return mid
        case n > get_sum(mid):
            lo = mid+1
            ans = mid
        }
    }
    return ans
}

func get_sum(x int) int {
    return (x+1)*x/2
}
