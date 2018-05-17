#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    std::stack<int> st;
    int n_upstream_live = 0;
    for (int i = 0; i < A.size(); ++i) {
        int fish_size = A[i];
        if (B[i]) st.push(fish_size);
        else {
            while (!st.empty()) {
                int top_size = st.top();
                if (top_size > fish_size) break;
                else {
                    st.pop();   
                }
            }
            if (st.empty()) {
                ++n_upstream_live;
            }
        }
    }
    
    return n_upstream_live + st.size();
}
