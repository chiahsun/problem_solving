class Solution {
  String findDifferentBinaryString(List<String> nums) {
    final buf = StringBuffer();
    for (int i = 0; i < nums.length; ++i) {
        buf.write((nums[i][i] == '1') ? '0' : '1');
    }
    return buf.toString();
  }
}
