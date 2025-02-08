import 'dart:collection';
// 0  1  2  3 4  5
//      10
//   10
//         10   10
//   20

class NumberContainers {
  Map<int, int> nums = {};
  Map<int, SplayTreeSet<int>> m = {};
  NumberContainers() { }

  void change(int index, int number) {
    if (nums.containsKey(index)) {
        int oldValue = nums[index]!;
        m[oldValue]?.remove(index);
    }
    nums[index] = number;
    if (m.containsKey(number)) {
        m[number]?.add(index);
    } else {
        m[number] = SplayTreeSet<int>.of([index]);
    }
  }

  int find(int number) {
    return m[number]?.firstOrNull ?? -1;
  }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = NumberContainers();
 * obj.change(index,number);
 * int param2 = obj.find(number);
 */
