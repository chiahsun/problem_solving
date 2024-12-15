class Solution {
  List<String> summaryRanges(List<int> nums) {
    if (nums.isEmpty) return [];

    int? start = null, end = null;
    // https://stackoverflow.com/questions/54031546/how-to-create-an-empty-list-in-dart
    final List<String> res = [];
    for (final n in nums) {
        if (start == null) start = n;
        else {
            if (end == null) {
                if (n-start == 1) end = n;
                else              { res.add("$start"); start = n; }
            } else {
                if (n-end == 1) end = n;
                else { res.add("$start->$end"); start = n; end = null; }
            }
        }
    }
    if (end != null) res.add("$start->$end");
    else             res.add("$start");
    return res;
  }
}
