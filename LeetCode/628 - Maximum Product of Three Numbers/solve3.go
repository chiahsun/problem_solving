func maximumProduct(nums []int) int {
    maxs := []int{nums[0], nums[1], nums[2]}
    mins := []int{nums[0], nums[1]}
    sort.Ints(maxs)
    sort.Ints(mins)
   
    for i := 2; i < len(nums); i++ {
        x := nums[i]
        if i > 2 {
            updateMax(maxs, x)
        }
        updateMin(mins, x)
    }
    a, b := mins[0]*mins[1]*maxs[2], maxs[0]*maxs[1]*maxs[2]
    return max(a, b)
}

func updateMax(slice []int, a int) {
    if a > slice[0] {
        slice[0] = a
    }
    sort.Ints(slice)
}

func updateMin(slice []int, a int) {
    if a < slice[1] {
        slice[1] = a
    }
    sort.Ints(slice)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
