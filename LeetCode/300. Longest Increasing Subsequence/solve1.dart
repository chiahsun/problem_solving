import 'package:collection/collection.dart';

class Solution {
  int lengthOfLIS(List<int> nums) {
    List<int> lcs = [];
    for (final num in nums) {
        // https://api.flutter.dev/flutter/package-collection_collection/lowerBound.html
        int lb = lowerBound(lcs, num);
        if (lb >= lcs.length) lcs.add(num);
        else if (lcs[lb] > num) lcs[lb] = num;
    }
    return lcs.length;
  }
}
