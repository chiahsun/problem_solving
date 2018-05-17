#include <stack>

int solution(vector<int> &H) {
    int count = 0;
    int height = 0;
    std::stack<int> st;
    for (int h : H) {
        while (height > h) {
            int val = st.top(); st.pop();
            height -= val;
        }   
        if (height < h) {
            int d = h - height;
            st.push(d);
            height += d;
            ++count;
        }
    }
    
    return count;
}
