#include <cstdio>
#include <cassert>
#include <utility>
#include <iostream>

#define DEBUG(expr) do { std::cout << #expr << " : " << (expr) << " @ " << __LINE__ << std::endl; } while(0)

const bool debug = false;

char buf[50];

const int SIZE = 100000+5;
int dir[SIZE][2];
int left, right;

const int BEGIN = 0;
const int END = SIZE-1;

void remove_block(int x) {
    int x_left = dir[x][left];
    int x_right = dir[x][right];
    dir[x_left][right] = x_right;
    dir[x_right][left] = x_left;
}

void add_block_left(int free, int y) {
    int y_left = dir[y][left];
    dir[y_left][right] = free;

    dir[free][left] = y_left;
    dir[free][right] = y;

    dir[y][left] = free;
}


void block_swap(int x, int y) {
    int x_right = dir[x][right] ;
    int y_right = dir[y][right];

    if (x_right == y)  {
        remove_block(y);
        add_block_left(y, x);
    } else if (y_right == x) {
        remove_block(x);
        add_block_left(x, y);
    } else {
        remove_block(x);
        remove_block(y);
        add_block_left(x, y_right);
        add_block_left(y, x_right);
    }

}

void print_from_begin(int line) {
    printf("left : %d\n", left);
    int curBegin = ((left == 0) ? BEGIN : END);
    int curEnd = ((curBegin == BEGIN) ? END : BEGIN);
    printf("(begin : %d) (end : %d)  @ %d\n", curBegin, curEnd, line);
    for (int i = dir[curBegin][right]; i != curEnd; i = dir[i][right])
        printf("%d ", i);
    printf("\n");
}

int main() {
    int N, M;
    int posCase = 1;
    while (scanf("%d%d\n", &N, &M) == 2) {
        if (debug) printf("Case: %d %d\n", N, M);
        left = 0;
        right = 1;
        for (int i = 1; i <= N; ++i) {
            dir[i][right] = i+1;
            dir[i][left] = i-1;
        }
        dir[N][right] = END;
        dir[BEGIN][left] = BEGIN;
        dir[BEGIN][right] = 1;
        dir[END][left] = N;
        dir[END][right] = END;
//        print_from_begin(__LINE__);
        while (M--) {
            scanf("%[^\n]\n", buf);
            if (debug) printf("buf: %s\n", buf);
            int CMD, X, Y;
            sscanf(buf, "%d%d%d", &CMD, &X, &Y);

            if (debug) printf("%d %d %d\n", CMD, X, Y);
            if (CMD == 1 and dir[Y][left] == X)
                continue;
            if (CMD == 2 and dir[Y][right] == X)
                continue;
            if (CMD == 1 or CMD == 2) {
                if (CMD == 1 and dir[Y][right] == X) block_swap(X, Y);
                else if (CMD == 2 and dir[Y][left] == X) block_swap(X, Y);
                else {
                    remove_block(X);

                    if (CMD == 1) add_block_left(X, Y);
                    else add_block_left(X, dir[Y][right]);
                }
            } else if (CMD == 3) {
                block_swap(X, Y);
            } else {
                std::swap(left, right);
            }
//            print_from_begin(__LINE__);
        }
        int curBegin = ((left == 0) ? BEGIN : END);
        int curEnd = (curBegin == BEGIN) ? END : BEGIN;
        unsigned long long sum = 0;
        for (int i = dir[curBegin][right]; i != curEnd; ) {
            sum += i;
            i = dir[i][right];
            i = dir[i][right];
        }
        printf("Case %d: %llu\n", posCase++, sum);
    }
    return 0;
}
