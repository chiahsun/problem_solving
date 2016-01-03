#include <cstdio>

int main() {
    int nCig, nChange;
    while (scanf("%d%d", &nCig, &nChange) == 2) {
        int sum = 0;
        while (nCig >= nChange) {
            int nGain = nCig / nChange;
            int nRemove = nGain * nChange;
            sum += nRemove;
            nCig = nCig - nRemove + nGain;
        }
        sum += nCig;
        printf("%d\n", sum);
    }
    return 0;
}
