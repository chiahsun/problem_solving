import 'package:collection/collection.dart';

class RandomizedSet {
  Map<int, int> m = {};
  List<int> l = [];
  final random = Random();

  RandomizedSet() { }

  bool insert(int val) {
    if (m.containsKey(val)) return false;
    m[val] = l.length;
    l.add(val);
    return true;
  }

  bool remove(int val) {
    if (!m.containsKey(val)) return false;

    int removePos = m[val]!;
    // https://api.flutter.dev/flutter/package-collection_collection/ListExtensions/swap.html
    if (removePos != l.length-1) {
        int other = l.last;
        l.swap(removePos, l.length-1);
        m[other] = removePos;
    }
    m.remove(val);
    l.removeLast();
    return true;
  }

  int getRandom() {
    return l[random.nextInt(l.length)];
  }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = RandomizedSet();
 * bool param1 = obj.insert(val);
 * bool param2 = obj.remove(val);
 * int param3 = obj.getRandom();
 */
