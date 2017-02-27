#include <iostream>
#include <stack>

int main() {
    int T, N, x;
    int a[1000];
    int gne[1000];
    std::stack<int> st, pos;
    std::cin >> T;

    while (T--) {
        st = std::stack<int>();

        std::cin >> N;
        for (int i = 0; i < N; ++i) {
            std::cin >> x;
            a[i] = x; 
            gne[i] = -1;
            while (!st.empty() && st.top() < x) {
                gne[pos.top()] = x;
                st.pop(); pos.pop();
            }
            st.push(x);
            pos.push(i);
        }
        for (int i = 0; i < N; ++i) {
            std::cout << gne[i] << ((i == N-1) ? "\n" : " ");
        }

    }
    return 0;
}
