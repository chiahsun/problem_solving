class Queue {
public:
    std::stack<int> st_push, st_pop;
    // Push element x to the back of queue.
    void push(int x) {
        st_push.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        pump();
        st_pop.pop();
    }

    void pump() {
        if (st_pop.size() == 0) {
            while (not st_push.empty()) {
                st_pop.push(st_push.top());
                st_push.pop();
            }
        }
    }
    // Get the front element.
    int peek(void) {
        pump();
        return st_pop.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        pump();
        return st_pop.size() == 0;
    }
};
