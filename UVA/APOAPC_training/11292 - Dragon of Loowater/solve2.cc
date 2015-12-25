#include <cstdio>
#include <algorithm>

const int MAX = 20000;
int x[MAX];
int y[MAX];

int main() {
    int nx, ny;
    while (scanf("%d%d", &nx, &ny) == 2 && nx) {
        for (int i = 0; i < nx; ++i) scanf("%d", &x[i]);
        for (int i = 0; i < ny; ++i) scanf("%d", &y[i]);

        std::sort(x, x+nx);
        std::sort(y, y+ny);

        int cost = 0;
        int posx = 0;
        for (int posy = 0; posy < ny && posx < nx; ++posy) {
            if (y[posy] >= x[posx]) {
                cost += y[posy];
                ++posx;
            }
        }
        if (posx == nx) 
            printf("%d\n", cost);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}
