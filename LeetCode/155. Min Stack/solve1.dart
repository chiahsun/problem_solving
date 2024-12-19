class MinStack {

  final List<int> st = [], mins = [];

  MinStack() { }

  void push(int val) {
    st.add(val);
    if (mins.isEmpty) { mins.add(val); }
    else              { mins.add(min(val, mins.last)); }
  }

  void pop() {
    st.removeLast();
    mins.removeLast();
  }

  int top() {
    return st.last;
  }

  int getMin() {
    return mins.last;
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = MinStack();
 * obj.push(val);
 * obj.pop();
 * int param3 = obj.top();
 * int param4 = obj.getMin();
 */
