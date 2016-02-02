#include <cstdio>
#include <algorithm>

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int lenPole, nAnts, x;
        scanf("%d%d", &lenPole, &nAnts);
        int least = 0, distance_min = lenPole, distance_max = 0;
        for (int i = 0; i < nAnts; ++i) {
            scanf("%d", &x);
            least = std::max(least, std::min(x, lenPole-x));
            distance_min = std::min(distance_min, x);
            distance_max = std::max(distance_max, x);
        }

        printf("%d %d\n", least, std::max(lenPole - distance_min, distance_max));
    }

    return 0;
}
