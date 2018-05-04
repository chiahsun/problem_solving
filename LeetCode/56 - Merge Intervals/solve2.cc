/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        
        std::sort(intervals.begin(), intervals.end(), [](const Interval & x, const Interval & y) {
            return x.start < y.start;
        });
        
        std::vector<Interval> ans = {intervals[0]};
        for (const auto & interval : intervals) {
            int start = interval.start;
            int end = interval.end;
            
            if (start > ans.back().end) ans.push_back(interval);
            else if (end > ans.back().end) ans.back().end = end;
        }
        
        return ans;
    }
};
