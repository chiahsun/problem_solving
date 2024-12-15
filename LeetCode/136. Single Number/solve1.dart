class Solution {
  int singleNumber(List<int> nums) {
    return nums.reduce((accu, elem) {
        return accu ^ elem;
    });
  }
}
