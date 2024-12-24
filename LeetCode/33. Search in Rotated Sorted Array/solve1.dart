class Solution {
  int search(List<int> nums, int target) {
    if (nums.isEmpty) return -1;
    if (nums.length == 1 && nums.first != target) return -1;
    if (nums.first > nums.last) {
        int N = (nums.length + 1) ~/ 2;
        int pos = search(nums.sublist(0, N), target);
        if (pos != -1) return pos;
        pos = search(nums.sublist(N), target);
        if (pos != -1) return N+pos;
        return -1;
    }
    if (target < nums.first || target > nums.last) return -1;
    int lo = 0, hi = nums.length-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) ~/ 2;
        if (nums[mid] == target) { return mid; }
        if (nums[mid] < target) { lo = mid+1; }
        else                    { hi = mid-1; }
    }

    return -1;
  }
}
