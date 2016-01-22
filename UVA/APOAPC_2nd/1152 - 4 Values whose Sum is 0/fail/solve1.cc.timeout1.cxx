#include <cstdio>
#include <vector>
#include <set>
const int M = 4000+5;

int A[4][M];


int main() {
    int nCase, N;
    bool firstCase = true;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 4; ++k) {
                scanf("%d", &A[k][i]);
            }

        std::set<int> s;
        for (int i = 0; i < N; ++i) 
            for (int k = 0; k < N; ++k)
                s.insert(A[0][i] + A[1][k]);
  
        int cnt = 0;
        for (int i = 0; i < N; ++i) 
            for (int k = 0; k < N; ++k) 
                if (s.count(-(A[2][i] +A[3][k])))
                    ++cnt;
        if (firstCase) firstCase = false;
        else printf("\n");
        printf("%d\n", cnt);
            
    }

    return 0;
}
