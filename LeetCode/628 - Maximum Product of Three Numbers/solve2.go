func maximumProduct(nums []int) int {
    maxs, mins := make([]int, 0, 3), make([]int, 0, 2)
   
    for _, v := range nums {
        maxs = updateMax(maxs, v)
        mins = updateMin(mins, v)
    }
    a, b := mins[0]*mins[1]*maxs[2], maxs[0]*maxs[1]*maxs[2]
    return max(a, b)
}

func updateMax(slice []int, a int) []int {
    if len(slice) < 3 {
        slice = append(slice, a)
    } else {
        if a > slice[0] {
            slice[0] = a
        }
    }
    sort.Ints(slice)
    return slice
}

func updateMin(slice []int, a int) []int {
    if len(slice) < 2 {
        slice = append(slice, a)
    } else {
        if a < slice[len(slice)-1] {
            slice[len(slice)-1] = a
        }
    }
    sort.Ints(slice)
    return slice
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
