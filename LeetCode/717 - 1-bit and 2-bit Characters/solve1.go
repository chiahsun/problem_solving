func isOneBitCharacter(bits []int) bool {
    last := 0
    for i := 0; i < len(bits); {
        last = bits[i]
        if last == 0 {
            i++
        } else {
            i += 2
        }
    }
    return last == 0
}
