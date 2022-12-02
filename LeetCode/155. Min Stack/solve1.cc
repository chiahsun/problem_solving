#include <iostream>
#include <queue>
#include <stack>

class MinStack {
    struct Node {
        bool _valid; 
        int _val;
        Node(int x) : _valid(true), _val(x) { }
    };

    struct NodeCompare {
        bool operator () (const Node* px, const Node* py) const { return px->_val > py->_val; }
    };

    std::priority_queue<Node*, std::vector<Node*>, NodeCompare> _pq;
    std::stack<Node*> _v; 
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        Node* p = new Node(x);
        _pq.push(p);
        _v.push(p); 
    }
    
    void pop() {
        top();
        if (not _v.empty()) {
            Node* p = _v.top(); _v.pop();
            p->_valid = false;
        }        
    }
    
    int top() {
        while (not _v.empty()) {
            Node* p = _v.top(); 
            if (p->_valid) {
                return p->_val;
            } else {
                _v.pop();
                delete p; p = nullptr;
            }
        }
        return -1;
    }

    
    int getMin() {
        while (not _pq.empty()) {
            Node* p = _pq.top(); 
            if (p->_valid) {
                return p->_val;
            } else {
                _pq.pop();
                delete p; p = nullptr;
            }
        }        
        return 0;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; //  --> Returns -3.
    minStack.pop();
    std::cout << minStack.top() << std::endl;    //  --> Returns 0.
    std::cout << minStack.getMin() << std::endl; // --> -2
    return 0;
}
