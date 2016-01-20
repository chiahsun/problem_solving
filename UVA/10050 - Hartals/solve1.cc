#include <cstdio>
#include <cstring>
const int M = 3650+5;

bool D[M];
int main() {
    int nCase, nDay, nParty;
    scanf("%d", &nCase);
    while (nCase--) {
        memset(D, true, sizeof(D));
        scanf("%d%d", &nDay, &nParty);

        int nLoss = 0;
        while (nParty--) {
            int cur;
            scanf("%d", &cur);
            for (int i = 0; i <= nDay; i += cur) {
                if (i != 0) {
                    int mod = i % 7;
                    if (D[i] and mod != 6 and mod != 0) {
                        D[i] = false;
                        ++nLoss;
                    }
                }
            }
        }

        printf("%d\n", nLoss);
    }
    return 0;
}
