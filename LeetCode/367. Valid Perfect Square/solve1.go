func isPerfectSquare(num int) bool {
    
    var last int64 = 0    
    var factor int64 = 2
    var a int64 = int64(num)
    
    for a > 1 && factor * factor <= a {
        for a % factor == 0 {
            if last != 0 {
                if last == factor {
                    last = 0
                } else {
                    return false
                }
            } else {
                last = factor
            }
            a /= factor
        }
        factor++
    }
    
    return last == 0 && a == 1
}
