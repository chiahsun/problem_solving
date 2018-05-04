/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct LeftXComparator {
    bool operator () (const Interval & x, const Interval & y) {
        if (x.start != y.start) return x.start > y.start; // We deal with larger x first
        return x.end < y.end;
    }
};
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::unordered_map<int, int> mapStartToIndex;
        for (int i = 0; i < intervals.size(); ++i) mapStartToIndex[intervals[i].start] = i;
        
        std::sort(intervals.begin(), intervals.end(), LeftXComparator());

        int rightmost_start = (intervals.empty() ? -1 : intervals.front().start);
        std::vector<int> ans(intervals.size(), -1);
        std::set<int> s;
        for (const auto & interval : intervals) {
            int index = mapStartToIndex[interval.start];
            int end = interval.end;
            
            if (end > rightmost_start) ans[index] = -1;
            else ans[index] = mapStartToIndex[*(s.lower_bound(end))];

            s.insert(interval.start);
        }
        
        return ans;
    }
};
