import 'package:collection/collection.dart';

class Solution {
  List<List<int>> permute(List<int> nums) {
    List<List<int>> res = [];
    final int N = nums.length;
    void dfs(int pos) {
        if (pos == N) { res.add(List.from(nums)); }
        else {
            for (int i = pos; i < N; ++i) {
                // https://api.flutter.dev/flutter/package-collection_collection/ListExtensions/swap.html
                nums.swap(pos, i);
                dfs(pos+1);
                nums.swap(pos, i);
            }
        }
    }
    dfs(0);
    return res;
  }
}
