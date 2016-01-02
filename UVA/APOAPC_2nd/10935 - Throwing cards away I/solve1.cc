#include <cstdio>

#include <queue>

int main() {
    int N;
    while (scanf("%d", &N) && N) {
        std::queue<int> q;
        for (int i = 1; i <= N; ++i) { q.push(i); }


        printf("Discarded cards:%s", q.size() == 1 ? "" : " ");
        bool first = true;
        while (q.size() >= 2) {
            if (first) first = false;
            else       printf(", ");
            printf("%d", q.front()); q.pop();
            int x = q.front(); q.pop();
            q.push(x);
        }
        printf("\nRemaining card: %d\n", q.front());
    }
    return 0;
}
