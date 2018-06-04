func getCharMap(S string) map[rune]int {
    m := make(map[rune]int)
    for _, r := range S {
        _, ok := m[r]
        if !ok {
            m[r] = 0
        } else {
            m[r]++
        }
    }
    return m
}

func canConstruct(ransomNote string, magazine string) bool {
    mRandom := getCharMap(ransomNote)
    mMagazine := getCharMap(magazine)
    
    for c, cnt := range mRandom {
        val, ok := mMagazine[c]
        if !ok || val < cnt {
            return false
        }
    }
    return true
}
