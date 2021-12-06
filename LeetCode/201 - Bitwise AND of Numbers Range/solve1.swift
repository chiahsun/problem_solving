class Solution {

    //   10100 a
    //   10011 b
    //   10111 a|b=c
    //   00100 b^c
    func findRightMostBit(_ a: Int) -> Int {
        if a == 0 { return 0 }
        let b = a-1
        let c = a|b
        return b^c
    }
    
    // Find left most identical prefix and find its ones
    // For a > b, there would exists some position that a is 1 and b is 0 from MSB.
    
    //   10110110 a
    //   10110011 b
    //   10110010 c=a&b
    //   00000101 d=a^b
    
    //   10110000 ans
    
    func rangeBitwiseAnd(_ left: Int, _ right: Int) -> Int {
        if left == right { return left }
        
        var (a, b) = (left, right)
        if b > a { (a, b) = (b, a) }
        
        let c = a & b
        let d = a ^ b
        var ans = c
        while ans > 0 {
            let rb = findRightMostBit(ans)
            if rb == 0 { break }
            if rb < d { ans = ans ^ rb } 
            else { break }
        }
        
        return ans
    }
}