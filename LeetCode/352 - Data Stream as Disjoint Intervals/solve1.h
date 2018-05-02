/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class SummaryRanges {
    std::map<int, Interval> m_;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        const auto it = m_.lower_bound(val);
        auto prev = it;
        if (prev == m_.begin()) prev = m_.end(); 
        else --prev;
            
        if (it == m_.end()) { 
            if (prev != m_.end()) {
                if (prev->second.end >= val) { }
                else if (prev->second.end+1 == val) { prev->second = Interval(prev->first, val); }
                else { m_.insert(it, std::make_pair(val, Interval(val, val))); }
            } else {
                m_.insert(it, std::make_pair(val, Interval(val, val))); 
            }
        } else if (it->first == val || (prev != m_.end() && prev->second.end >= val)) { 
        } else {
            //        |
            // .     it
            //    |
            // |
            if (val+1 == it->first) {
                int it_end = it->second.end;
                m_.erase(it);
                m_.insert(std::make_pair(val, Interval(val, it_end)));
            } else {
                m_[val] = Interval(val, val);
            }
            
            if (prev != m_.end()) {
                auto it_val = m_.find(val);
                int val_end = it_val->second.end;
                if (prev->second.end+1 == val) {
                    m_.erase(it_val);
                    // Cannot use m_.insert(std::make_pair(prev->first, Interval(prev->first, val_end)));
                    // since if there is existed key, the value won't be updated
                    m_[prev->first] = Interval(prev->first, val_end);
                }
            }
        }
    }
    
    vector<Interval> getIntervals() {
        std::vector<Interval> ans;
        for (const auto & pr : m_) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
