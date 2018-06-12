func findErrorNums(nums []int) []int {
    cnts := make([]int, len(nums)+1)
    
    for _, v := range nums {
        cnts[v]++
    }
    ans := make([]int, 2)
    for i := 1; i < len(cnts); i++ {
        switch cnts[i] {
        case 0:
             ans[1] = i
        case 2:
             ans[0] = i 
        default:
        }
        if ans[0] > 0 && ans[1] > 0 {
            break
        }
    }
    
    return ans
}
