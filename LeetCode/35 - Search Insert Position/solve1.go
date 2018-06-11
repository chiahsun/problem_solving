func searchInsert(nums []int, target int) int {
    if len(nums) == 0 || target <= nums[0] {
        return 0
    }
    if target > nums[len(nums)-1] {
        return len(nums)
    }
    lo, hi := 0, len(nums)-1
    ans := 0
    for lo <= hi {
        mid := (lo+hi)/2
        if (nums[mid] <= target) {
            ans = mid
            lo = mid+1
        } else {
            hi = mid-1
        }
    }
    if nums[ans] == target {
        return ans
    }
    return ans+1
}
