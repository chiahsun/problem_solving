// https://api.flutter.dev/flutter/package-collection_collection/ListExtensions/swap.html
import 'package:collection/collection.dart';

class Solution {
  int removeElement(List<int> nums, int val) {
    int i = 0, k = nums.length-1;
    while (k >= 0 && nums[k] == val) --k;
    while (i <= k) {
        if (nums[i] == val) {
            nums.swap(i, k--);
        } else {
            i++;
        }
    }
    return k+1;
  }
}
