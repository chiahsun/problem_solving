class MyCalendar {
    std::map<int, int> m;
public:
    MyCalendar() {    
    }
    
    bool book(int start, int end) {
        std::cout << "Start " << start << " end " << end << std::endl;
        
        auto it = m.lower_bound(start);
        if (it != m.end()) std::cout << "  Found " << it->first << " " << it->second << std::endl;
        if (it == m.end()) {
            if (m.empty()) {
                m.insert(std::make_pair(start, end));
                return true;
            } else {
                --it;
                if (start < it->second) {
                    return false;
                } else {
                    m.insert(std::make_pair(start, end));
                    return true;
                }
            }
        }
        
        if (it->first == start) return false;
        if (end > it->first) return false;
        if (it == m.begin()) {
            m.insert(std::make_pair(start, end));
            return true;
        }
        --it;
        if (start < it->second) {
            return false;
        } else {
            m.insert(std::make_pair(start, end));
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
