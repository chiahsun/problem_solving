func arrangeCoins(n int) int {
    K := 2 * n
    x := K
    
    for f(x) < 0 || f(x) > K {
        x = (x + (2*K-x)/(2*x+1))/2
    }
    return x
}

func f(x int) int {
    return x*x + x
}
