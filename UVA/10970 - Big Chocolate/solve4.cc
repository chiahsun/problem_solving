#include <cstdio>
#include <algorithm>

const int M = 300;

int table[M+1][M+1];
int square_cost[M+1];

int get_cost(int x, int y) {
    if (x == 1) return y-1;
    return (x <= y) ? table[x][y] : get_cost(y, x);
}


int main() {
    square_cost[1] = 0;
    for (int i = 2; i <= M; ++i)
        square_cost[i] = square_cost[i-1] + i-1 + i-2 + 2;

    for (int numRow = 2; numRow <= 300; ++numRow)
        for (int numCol = numRow; numCol <= 300; ++numCol) {
            int nSquare = numCol / numRow;
            int left = numCol - nSquare * numRow;
            int cost = square_cost[numRow] * nSquare + nSquare-1;
            if (left > 0)
                cost = cost + 1 + get_cost(numRow, left);
            table[numRow][numCol] = cost; 
        }

    int x, y;
    while (scanf("%d%d", &x, &y) == 2) {
        printf("%d\n", get_cost(x, y));
    }
    return 0;
}
