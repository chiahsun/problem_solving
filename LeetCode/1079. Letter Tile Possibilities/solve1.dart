import 'package:collection/collection.dart';

class Solution {
  int numTilePossibilities(String tiles) {
    var T = tiles.split('')..sort(), L = <int>[];
    for (var i = 0, last = '-'; i < tiles.length; ++i) {
        String c = T[i];
        if (c != last) { L.add(0); last = c; }
        ++L.last;
    }

    int permutation(int take) {
        int cnt = 0;
        void backtracking(int pos) {
            if (pos == take) { ++cnt; return; }
            for (int i = 0; i < L.length; ++i) {
                if (L[i] > 0) {
                    --L[i];
                    backtracking(pos+1);
                    ++L[i];
                }
            }
        }
        backtracking(0);
        return cnt;
    }

    return [for (int i = 1; i <= tiles.length; ++i) permutation(i)].sum;
  }
}
