class Solution {
  List<int> twoSum(List<int> numbers, int target) {
    int i = 0, k = numbers.length-1;
    while (numbers[i] + numbers[k] != target) {
        if (numbers[i] + numbers[k] > target) k--;
        else                            ++i;
    }
    return [i+1, k+1];
  }
}
