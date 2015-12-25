#include <cstdio>
#include <algorithm>

const int MAX = 20000 + 5;
int heads[MAX];
int heros[MAX];

int main() {
    int numHead, numHero;

    while (scanf("%d%d", &numHead, &numHero) == 2 && numHead) {
        for (int i = 0; i < numHead; ++i) {
            int x;
            scanf("%d", &x);
            heads[i] = x;
        }

        for (int i = 0; i < numHero; ++i) {
            int x;
            scanf("%d", &x);
            heros[i] = x;
        }

        std::sort(heads, heads+numHead);
        std::sort(heros, heros+numHero);

        bool fail = false;
        int cost = 0;
        for (int posHead = 0, posHero = 0; posHead < numHead; ) {
            if (posHero >= numHero) {
                fail = true;
                break;
            }
            for (;posHero < numHero; ++posHero) {
                if (heros[posHero] >= heads[posHead]) {
                    cost += heros[posHero];
                    ++posHero;
                    ++posHead;
                    break;
                }
            }

        }

        if (!fail) 
            printf("%d\n", cost);
        else
            printf("Loowater is doomed!\n");
        

    }

    return 0;
}
