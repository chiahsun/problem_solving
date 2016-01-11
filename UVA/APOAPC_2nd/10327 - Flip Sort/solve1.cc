#include <cstdio>
#include <algorithm>

const int M = 1000+5;
int a[M];

int main() {
    int nElement;

    while (scanf("%d", &nElement) == 1 && nElement) {
        for (int i = 0; i < nElement; ++i)
            scanf("%d", a + i);
       
        bool stable = false; 
        int cnt = 0;
        while (not stable) {
            stable = true;
            for (int i = 0; i < nElement-1; ++i) {
                if (a[i] > a[i+1]) {
                    std::swap(a[i], a[i+1]);
                    ++cnt;
                    stable = false;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
