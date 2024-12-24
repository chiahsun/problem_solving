import 'package:collection/collection.dart';

class MedianFinder {
  // https://api.flutter.dev/flutter/package-collection_collection/PriorityQueue-class.html
  final minQ = PriorityQueue<int>();
  final maxQ = PriorityQueue<int>((a, b) => -a.compareTo(b));
  MedianFinder() {

  }

  //              [7 9 11] minQ
  // maxQ [1 3 ]
  void addNum(int num) {
    if (minQ.length >= maxQ.length) {
        if (!minQ.isEmpty && num > minQ.first) {
            final f = minQ.removeFirst();
            maxQ.add(f);
            minQ.add(num);
        } else {
            maxQ.add(num);
        }
    } else {
         if (!maxQ.isEmpty && num < maxQ.first) {
            final f = maxQ.removeFirst();
            minQ.add(f);
            maxQ.add(num);
        } else {
            minQ.add(num);
        }
    }

  }

  double findMedian() {
    if (minQ.length > maxQ.length) return minQ.first.toDouble();
    if (maxQ.length > minQ.length) return maxQ.first.toDouble();
    if (!minQ.isEmpty) return (minQ.first.toDouble() + maxQ.first.toDouble()) / 2;
    return 0;
  }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = MedianFinder();
 * obj.addNum(num);
 * double param2 = obj.findMedian();
 */
