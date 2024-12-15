func reverseBits(num uint32) uint32 {
    var mul, res uint32 = 1 << 31, 0
    for num > 0 {
        if num & 1 > 0 { res += mul }
        mul >>= 1
        num >>= 1
    }
    return res
}
