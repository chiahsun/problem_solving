#include <cstdio>
#include <algorithm>

const int M = 1000000+5;
int distance[M];

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int lenPole, nAnts;
        scanf("%d%d", &lenPole, &nAnts);
        for (int i = 0; i < nAnts; ++i)
            scanf("%d", distance+i);
        std::sort(distance, distance+nAnts);
        int least = 0;
        for (int i = 0; i < nAnts; ++i)
            least = std::max(least, std::min(distance[i], lenPole-distance[i])); 

        printf("%d %d\n", least, std::max(lenPole - distance[0], distance[nAnts-1]));
    }

    return 0;
}
