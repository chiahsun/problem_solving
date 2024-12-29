//  1  2  3  4  5
//  3  4  5  1  2
// -2 -2 -2  3  3
// -2 -4 -6  -3 0

class Solution {
  int canCompleteCircuit(List<int> gas, List<int> cost) {
    int total = 0, lastMin = 0, res = 0;
    for (int i = 0; i < gas.length; ++i) {
        final cur = gas[i] - cost[i];
        total += cur;
        if (total < lastMin) {
            res = i+1;
            lastMin = total;
        }
    }
    return (total >= 0) ? res : -1;
  }
}
