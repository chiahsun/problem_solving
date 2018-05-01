class MyCalendar {
    std::map<int, int> m;
public:
    MyCalendar() {    
    }
    
    bool book(int start, int end) {
        
        auto next = m.lower_bound(start);
        auto prev = next;
        if (next == m.begin() || m.empty()) { prev = m.end(); }
        else { --prev; }
        
        if (next != m.end() && end > next->first) return false;
        if (prev != m.end() && start < prev->second) return false;
        
        m.insert(std::make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

