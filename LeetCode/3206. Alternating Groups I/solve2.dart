import 'package:collection/collection.dart';

class Solution {
  int numberOfAlternatingGroups(List<int> colors) {
     final N = colors.length;

    int prev(int i) => (i > 0) ? (i - 1) : (N - 1);
    int next(int i) => (i == N-1) ? 0 : (i + 1);
    int isAlt(int i) => (colors[i] != colors[prev(i)] && colors[i] != colors[next(i)]) ? 1 : 0;
    return [for (int i = 0; i < N; ++i) isAlt(i)].sum;
  }
}
