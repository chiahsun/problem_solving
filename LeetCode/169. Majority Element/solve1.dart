class Solution {
  int majorityElement(List<int> nums) {
    int target = 0, cnt = 0;
    for (final cur in nums) {
        if (cur == target) {
            ++cnt;
        } else {
            if (cnt == 0) { target = cur; cnt = 1; }
            else { --cnt; }
        }
    }
    return target;
  }
}
