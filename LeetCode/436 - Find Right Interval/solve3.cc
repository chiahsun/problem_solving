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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::vector<int> ans(intervals.size());
        std::map<int, int> m; // start, index
        
        int rightmost_start = (intervals.empty() ? -1 : intervals.front().start);
        for (int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i].start;
            m[start] = i;
            rightmost_start = std::max(rightmost_start, start);
        }
        
        for (int i = 0; i < ans.size(); ++i) {
            int end = intervals[i].end;
            
            if (end > rightmost_start) ans[i] = -1;
            else ans[i] = m.lower_bound(end)->second;
        }
        
        return ans;
    }
};
