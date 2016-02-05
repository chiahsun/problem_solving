#include <cstdio>
#include <queue>
#include <functional>

const int M = 20000+5;
int A[M];

int main() {
    int nPlank;
    while (scanf("%d", &nPlank) == 1 and nPlank) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        for (int i = 0; i < nPlank; ++i) { 
            scanf("%d", A+i);
            pq.push(A[i]);
        }

        long long sum = 0;
        while (pq.size() != 1) {
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();

            int s = t1 + t2;
//            printf("%d %d -> %d\n", t1, t2, s);
            sum += s;
            pq.push(s);
        }
        
        printf("%lld\n", sum);
        
    }
    return 0;
}
