#include <cstdio>
#include <algorithm>

const int M = 300;

int table[M+1][M+1];

int get_cost(int x, int y) {
    return (x <= y) ? table[x][y] : table[y][x];
}


int main() {

    for (int numCol = 1; numCol <= 300; ++numCol)
        table[1][numCol] = numCol-1;

    for (int numRow = 2; numRow <= 300; ++numRow)
        for (int numCol = numRow; numCol <= 300; ++numCol) {
//            printf("[%d][%d]\n", numRow, numCol);
            int cost = M * M;
            for (int i = 1; i <= numRow/2; ++i) 
                cost = std::min(cost, 1 + get_cost(i, numCol) + get_cost(numRow-i, numCol));
            for (int k = 1; k <= numCol/2; ++k) 
                cost = std::min(cost, 1 + get_cost(numRow, k) + get_cost(numRow, numCol-k));
            table[numRow][numCol] = cost;
        }

    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d\n", get_cost(x, y));
    }
    return 0;
}
