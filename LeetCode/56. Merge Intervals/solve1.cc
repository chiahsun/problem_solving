/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct StartComparator {
    // We deal with larger start first
    bool operator () (const Interval & x, const Interval & y) const {
        if (x.start != y.start) return x.start > y.start;
        return x.end > y.end;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), StartComparator());
        
        std::list<Interval> list;
        for (const auto & interval : intervals) {
            // start <= ans.front().start
            // end may be larger than ans[i].end
            int start = interval.start;
            int end = interval.end;
            
            while (!list.empty() && end >= list.front().end) {
                list.pop_front();
            }
            if (!list.empty() && end >= list.front().start) {
                end = list.front().end;
                list.pop_front();
            }
            list.push_front(Interval(start, end));
        }
        
        std::vector<Interval> ans;
        ans.reserve(list.size());
        ans.insert(ans.end(), list.begin(), list.end());
        return ans;
    }
};
