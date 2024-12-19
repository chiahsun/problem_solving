import 'dart:collection';

class LRUCache {
  final q = Queue<int>();
  Map<int, int> mVal = {}, mCnt = {};
  int uniqueCnt = 0;
  // https://dart.dev/language/classes
  final int capacity;
  LRUCache(this.capacity) { }

  int get(int key) {
    if (!mCnt.containsKey(key) || mCnt[key] == 0) return -1;

    q.add(key);
    mCnt.update(key, (val) => ++val, ifAbsent: () => 1);
    return mVal[key]!;
  }

  void put(int key, int value) {
    mVal[key] = value;

    q.add(key);
    if (!mCnt.containsKey(key) || mCnt[key] == 0) {
        mCnt[key] = 1; ++uniqueCnt;
    } else {
        mCnt.update(key, (val) => ++val, ifAbsent: () => 1);
    }
    if (uniqueCnt > capacity) {
        while (!q.isEmpty) {
            int front = q.removeFirst();
            mCnt.update(front, (val) => --val, ifAbsent: () => 1);
            if (mCnt[front] == 0) {
                --uniqueCnt;
                break;
            }
        }
    }
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = LRUCache(capacity);
 * int param1 = obj.get(key);
 * obj.put(key,value);
 */
