class MinStack {
public:
    std::vector<std::pair<int, int> > _v;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        int vmin = (not _v.empty() ? std::min(_v.back().second, x) : x);
        _v.push_back(std::make_pair(x, vmin));
    }
    
    void pop() {
        _v.pop_back();
    }
    
    int top() {
        return _v.back().first;
    }
    
    int getMin() {
        return _v.back().second;
    }
};
