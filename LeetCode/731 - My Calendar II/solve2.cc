class MyCalendarTwo {
    std::map<int, int> m; // start, count
public:
    MyCalendarTwo() {
    }
    
    void add_anchor(int position) {
        auto it = m.lower_bound(position);
        auto prev = it; // Try to find <= position
        if (prev == m.end()) {
            if (!m.empty()) --prev;
        } else { 
            if (prev->first > position) {
                if (prev == m.begin()) prev = m.end();
                else --prev;
            }
        }
        
        m[position] = ((prev != m.end()) ? prev->second : 0);
    }
    
    bool book(int start, int end) {
        add_anchor(start);
        add_anchor(end);
        auto it_begin = m.find(start), it_end = m.find(end); 
        for (auto it = it_begin; it != it_end; ++it) {
            if (it->second == 2) return false;
        }
   
        int lastValue = -1;
        for (auto it = it_begin; it != it_end;) {
            int newValue = it->second+1;
            if (newValue == lastValue) { it = m.erase(it); }
            else                       { lastValue = ++it->second; ++it; }
            // ++it->second; // work
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
