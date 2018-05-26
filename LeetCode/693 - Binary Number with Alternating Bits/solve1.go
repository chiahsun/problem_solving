func hasAlternatingBits(n int) bool {
    last := n&0x1
    for val := (n >> 1); val > 0; val >>= 1 {
        now := val & 0x1
        if now == last {
            return false
        }
        last = now
    }
    return true
}
