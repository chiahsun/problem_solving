package kata

import "math"

func Simpson(n int) float64 {
    var a float64 = 0
    b := math.Pi
    f := func(x float64) float64 {
        return 3 * math.Pow(math.Sin(x), 3) / 2
    }
    
    res1, res2 := 0.0, 0.0
    var h float64 = (b-a)/float64(n)
    for i := 1; i <= n/2; i++ {
        res1 += f(a + float64(2*i-1)*h)
    }
    for i:= 1; i <= n/2-1; i++ {
        res2 += f(a + 2*float64(i)*h)
    }
    
    return (b-a)*(f(a) + f(b) + 4*res1 + 2*res2)/3.0/float64(n)
}
