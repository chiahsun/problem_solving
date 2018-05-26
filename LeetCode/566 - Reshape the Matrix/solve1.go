func matrixReshape(nums [][]int, r int, c int) [][]int {
    if r * c != len(nums) * len(nums[0]) {
        return nums
    }
    
    a := make([][]int, r)
    ori_i, ori_k := 0, 0
    for i := 0; i < r; i++ {
        a[i] = make([]int, c)
        for k := 0; k < c; k++ {
            if ori_k == len(nums[0]) {
                ori_i++
                ori_k = 0
            }
            a[i][k] = nums[ori_i][ori_k]
            ori_k++
        }
    }
    
    return a
}
