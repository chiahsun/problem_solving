func getCharCounts(S string) []int {
    cnts := make([]int, 26)
    for _, r := range S {
        cnts[int(r - 'a')]++
    }
    return cnts
}

func canConstruct(ransomNote string, magazine string) bool {
    cntsRandom := getCharCounts(ransomNote)
    cntsMagazine := getCharCounts(magazine)
    
    for i := 0; i < len(cntsRandom); i++ {
        if cntsRandom[i] > cntsMagazine[i] {
            return false
        }
    }
    return true
}
