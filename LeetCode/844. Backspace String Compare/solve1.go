func getString(S string) string {
    a := make([] rune, 0)
    for _, c := range(S) {
        if c == '#' {
            if len(a) > 0 {
                a = a[:len(a)-1]
            }
        } else {
            a = append(a, c)
        }
    }
    return string(a)
}
func backspaceCompare(S string, T string) bool {
    return getString(S) == getString(T)
}
