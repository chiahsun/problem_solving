func toHex(num int) string {
    if num == 0 {
        return "0"
    }
    count := 8
    a := make([]byte, 0)
    m := [...]byte {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}
    for ;num != 0 && count > 0; {
        a = append(a, m[num & 0xf])
        count--
        num >>= 4
    }
    for i, k := 0, len(a)-1; i < k; {
        a[i], a[k] = a[k], a[i]
        i++
        k--
    }
    return string(a)
}
