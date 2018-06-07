func checkRecord(s string) bool {
    nAbsent, nContLate := 0, 0
    last := '0'
    for _, c := range s {
        switch c {
        case 'A':
            nAbsent++
            if nAbsent > 1 {
                return false
            }
        case 'L':
            if last == 'L' {
                nContLate++
                if nContLate > 2 {
                    return false
                }
            } else {
                nContLate = 1
            }
        default:
        }
        last = c
    }
    return true
}
