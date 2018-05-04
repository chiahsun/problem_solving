class RangeModule {
    std::map<int, int> m;
public:
    RangeModule() {
        
    }

    //    |----
    // .  |---- (1)
    //  |---| (2)
    std::map<int, int>::iterator find_less_than_if_possible(int left) {  
        auto it = m.lower_bound(left);
        
        if (it != m.end() && it->first == left) { }
        else {
            if (!m.empty() && it != m.begin()) {
                auto prev = it; --prev;
                if (prev->second >= left) {
                    it = prev;
                }
            }
        }
        return it;
    }
    
    void addRange(int left, int right) {
        auto begin = find_less_than_if_possible(left);
        auto end = m.upper_bound(right);
        int new_left = left;
        int new_right = right;
        if (begin != m.end()) new_left = std::min(new_left, begin->first);
        for (auto it = begin; it != end;) {
            new_right = std::max(new_right, it->second);
            it = m.erase(it);
        }
        
        m[new_left] = new_right;
    }
    
    bool queryRange(int left, int right) {
        auto it = find_less_than_if_possible(left);
        return (it != m.end()) && (it->first <= left) && (it->second >= right);
    }
    
    //  |----------|
    // |--|
    //    |---|
    void removeRange(int left, int right) {
        auto begin = find_less_than_if_possible(left);
        auto end = m.lower_bound(right);
       
        bool needAdd = false;
        int rightmost_left, rightmost_right;
        for (auto it = begin; it != end; ) {
            if (it->first < left) {
                if (it->second > right) {
                    needAdd = true;
                    rightmost_left = right;
                    rightmost_right = it->second;
                }
                m[it->first] = left;
                ++it;
            } else {
                if (it->second <= right) {
                    if (it->first < left) {
                        m[it->first] = left;
                    } else {
                        it = m.erase(it);
                    }
                } else {
                    needAdd = true;
                    rightmost_left = right;
                    rightmost_right = it->second;
                    it = m.erase(it);
                }
            }
        }
        
        if (needAdd) {
            m[rightmost_left] = rightmost_right;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

