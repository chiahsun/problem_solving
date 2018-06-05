func getTitle(pos int) string {
    switch pos {
        case 0: return "Gold Medal"
        case 1: return "Silver Medal"
        case 2: return "Bronze Medal"
        default: return strconv.Itoa(pos+1)
    }
}

type ByScore []int

func (a ByScore) Len() int { return len(a) }
func (a ByScore) Swap(i, k int) { a[i], a[k] = a[k], a[i] }
func (a ByScore) Less(i, k int) bool { return a[i] > a[k] }

func findRelativeRanks(nums []int) []string {
    mapScoreToPos := make(map[int]int)
    for i, v := range nums {
        mapScoreToPos[v] = i
    }
    sort.Sort(ByScore(nums))
    
    ans := make([]string, len(nums))
    for i, v := range nums {
        ans[mapScoreToPos[v]] = getTitle(i)
    }
    return ans
}
