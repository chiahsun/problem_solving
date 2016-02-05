class Stack {
public:
    std::queue<int> q[2];
    
    std::queue<int> & get_cur_queue() { return q[0].empty() ? q[1] : q[0]; }
    std::queue<int> & get_next_queue() { return q[0].empty() ? q[0] : q[1]; }
    
    int pop_helper() {
        std::queue<int> & qCur = get_cur_queue();
        std::queue<int> & qNext = get_next_queue();
        
        int sz = qCur.size();
        while (sz > 1) {
            int x = qCur.front(); qCur.pop(); --sz;
            qNext.push(x);
        }
        int top = 0;
        if (sz == 1) {
            top = qCur.front(); qCur.pop();
        }
        return top;
    }
    
    // Push element x onto stack.
    void push(int x) {
        std::queue<int> & qCur = get_cur_queue();
        qCur.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (not empty())
            pop_helper();
    }

    // Get the top element.
    int top() {
        int t = -1;
        if (not empty()) {
            t = pop_helper();
            get_cur_queue().push(t);
        }
        return t;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[0].empty() and q[1].empty();
    }
};
