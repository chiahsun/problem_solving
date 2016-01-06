#include <cstdio>
#include <stack>

int train[1000+5];

int main() {
    int nTrain;
    while (scanf("%d", &nTrain) == 1 && nTrain) {
        do {
            int pos = 1;
            scanf("%d", &train[pos++]);
            if (train[1] == 0)
                break;
            for (;pos <= nTrain; ++pos)
                scanf("%d", &train[pos]);
#if 0
            for (int i = 1; i <= nTrain; ++i)
                printf("%d ", train[i]);
            printf("\n");
#endif

            int A = 1;
            std::stack<int> st;

            for (int i = 1; i <= nTrain; ++i) {
                int cur = train[i];
                if (cur > A) {
                    while (cur > A) { st.push(A++); } 
                    ++A;
                } else if (cur < A) {
                    if (cur != st.top())
                        break;
                    st.pop();
                } else { ++A; }

            }
            printf("%s", ((st.size() == 0)? "Yes\n" : "No\n"));
        } while (1);
        printf("\n");
    }
}
