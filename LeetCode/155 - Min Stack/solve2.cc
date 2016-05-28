class MinStack {
public:
    std::vector<std::pair<int, int> > _m;
    std::vector<int>                  _v;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (_m.empty() or _m.back().first > x)
            _m.push_back(std::make_pair(x, _v.size()));
        _v.push_back(x);
    }
    
    void pop() {
        _v.pop_back();
        if (not _m.empty() and _m.back().second >= _v.size())
            _m.pop_back();
    }
    
    int top() {
        return _v.back();
    }
    
    int getMin() {
        return _m.back().first;
    }
};

