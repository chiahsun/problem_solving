#include <cstdio>
#include <cassert>
#include <cstring>

const int M = 200;
char board[M+5][M+5];

bool is_valid(char c) {
    const char invalid[4] = {'|', '-', '#', ' '};
    for (int i = 0; i < 4; ++i)
        if (c == invalid[i])
            return false;
    return c >= 33 and c <= 126;
} 

void print_node(int row, int col) {
    printf("%c(", board[row][col]);
    if (board[row+1][col] == '|') {
        int ddrow = row+2;
        assert(board[ddrow][col] == '-');

        int head = col;
        while (head >= 0 and board[ddrow][head] == '-') { --head; }
        ++head;

        int dddrow = row+3;
        for (int i = head; board[ddrow][i] == '-'; ++i) {
            if (is_valid(board[dddrow][i]))
                print_node(dddrow, i);
        }
    }
    printf(")");
}

int main() {
    int nCase;
    scanf("%d", &nCase); getchar();
    while (nCase--) {
        int nCol;
        memset(board, ' ', sizeof(board));
        for (int i = 0; i < M; ++i) {
            scanf("%[^\n]", board[i]); getchar();
            if (board[i][0] == '#') {
                board[i][0] = ' ';
                nCol = i;
                break;
            }
        }

        printf("(");
        for (int i = 0; i < M; ++i) {
            if (is_valid(board[0][i])) {
                print_node(0, i);
            }
        }
        printf(")\n");
#if 0
        for (int i = 0; i < nCol; ++i) {
            printf("%s\n", board[i]);
        }
#endif
    }
    return 0;
}
