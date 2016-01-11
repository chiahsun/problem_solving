#include <cstdio>
#include <algorithm>

const int M = 1000+5;
int a[M];

int main() {
    int nElement;

    while (scanf("%d", &nElement) == 1 && nElement) {
        for (int i = 0; i < nElement; ++i)
            scanf("%d", a + i);

        int cnt = 0;
        for (int i = 0; i < nElement-1; ++i) {
            int now = a[i];
            for (int k = i+1; k < nElement; ++k) {
                if (a[i] > a[k])
                    ++cnt;
            }
        }
       
        printf("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
