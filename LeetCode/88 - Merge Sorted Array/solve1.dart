class Solution {
  // https://dart.dev/language/collections#lists
  // https://dart.dev/libraries/dart-core#lists
  void merge(List<int> nums1, int m, List<int> nums2, int n) {
    m--; n--;
    var i = nums1.length - 1;
    while (n >= 0) {
        if (m < 0 || (n >= 0 && nums1[m] <= nums2[n])) {
            nums1[i--] = nums2[n--];
        } else {
            nums1[i--] = nums1[m--];
        }
    }
  }
}
