#include <cstdio>
#include <cstring>
const int M = 20+5;
int device[M];
bool toggle[M];

int main() {
    int ndevice, nop, capcity, posCase=1;
    while (scanf("%d%d%d", &ndevice, &nop, &capcity) == 3 and (ndevice or nop or capcity)) {
        int max_current = 0, op;
        for (int i = 1; i <= ndevice; ++i) 
            scanf("%d", device+i);
        memset(toggle, false, sizeof(toggle));

        int now_current = 0;
        while (nop--) {
            scanf("%d", &op);
            if (toggle[op]) now_current -= device[op];
            else now_current += device[op];
            if (now_current > max_current)
                max_current = now_current;

            toggle[op] = !toggle[op];
        }

        printf("Sequence %d\n", posCase++);
        if (max_current > capcity)
            printf("Fuse was blown.\n");
        else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max_current);
        }
        printf("\n");
    }
    return 0;
}
