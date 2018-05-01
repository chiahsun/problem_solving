/*struct Segment {
    int start, end, count;
    Segment(int st, int en) : start(st), end(en), count(1) { }
    Segment(int st, int en, int cnt) : start(st), end(en), count(cnt) { }
}*/

class MyCalendarThree {
    std::map<int, int> m;
    int max_;
public:
    MyCalendarThree() {
        max_ = 0;
    }
    void add_anchor(int position) {
         auto it = m.lower_bound(position);
        if (it != m.end()) {
            if (it->first == position) { }
            else { // it->first > position
                if (it != m.begin()) {
                    --it;
                    m[position] = it->second;
                } else {
                    m[position] = 0;
                }
            }
        } else {
            if (!m.empty()) {
                --it;
                m[position] = it->second;
            } else {
                m[position] = 0;
            }
        }
    }
    // Let [a, b, c, ...] be [a, b), [b, c), ...
    int book(int start, int end) {
        add_anchor(start);
        add_anchor(end);
        
        int max = 0;
        for (auto it = m.lower_bound(start); it != m.lower_bound(end); ++it) {
            max = std::max(max, ++it->second);
        }
        
        return (max_ = std::max(max, max_));
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
