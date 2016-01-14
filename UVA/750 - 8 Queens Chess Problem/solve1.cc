#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

const int M = 9;
int position[M]; // 1 to 8
int select_row, select_col;

bool conflict(int cur_col, int other_col) {
    assert(cur_col != other_col);
    return (position[cur_col] == position[other_col]) 
        or (abs(cur_col - other_col) == abs(position[cur_col] - position[other_col]));
}

void search(int cur_col, int & posSol) {
#if 0
    printf("temp sol: ");
    for (int i = 1; i <= cur_col; ++i)
        printf("%d ", position[i]);
    printf("\n");
#endif
    if (cur_col == 9) {
        printf("%2d     ", posSol++);
        for (int i = 1; i <= 8; ++i)
            printf(" %d", position[i]);
        printf("\n");
    }
    if (cur_col != select_col) {
        for (int r = 1; r <= 8; ++r) {
            position[cur_col] = r;
            bool ok = not conflict(cur_col, select_col);
            for (int i = 1; i < cur_col; ++i) {
                if (conflict(cur_col, i)) {
                    ok = false;
                    break;
                }
            }
           if (ok) 
                search(cur_col+1, posSol);
        }
    } else {
        search(cur_col+1, posSol);
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &select_row, &select_col);
        position[select_col] = select_row;
        int posSol = 1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        search(1, posSol);
        if (nCase)
            printf("\n");
    }
    return 0;
}
