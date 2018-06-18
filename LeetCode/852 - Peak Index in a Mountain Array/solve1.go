func peakIndexInMountainArray(A []int) int {
    ans := 0
    for i, v := range A {
        if v > A[ans] {
            ans = i
        } else if v < A[ans] {
            break
        }
    }
    return ans
}
