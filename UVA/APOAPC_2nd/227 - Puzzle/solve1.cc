#include <cstdio>
#include <cstring>
#include <cassert>
#include <utility>

const int MAX = 10;
char buf[MAX];

char board[5][5 + 5];
int px, py;

const char* END_SYMBOL = "Z";

void print_board() {
    printf("Initial board:\n");
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 5; ++k) {
            printf("%c", board[i][k]);
        }
        printf("\n");
    }
        printf("\n");
}

int main() {
    int posPuzzle = 1;
    while (fgets(buf, MAX, stdin) && strncmp(buf, END_SYMBOL, strlen(END_SYMBOL)) != 0) {
#if 0
        printf("Enter one with buf = %s, len = %zu, compare = %d\n", buf, strlen(buf), strcmp(buf, END_SYMBOL));
        printf(" the two = %d\n", buf[1]);
#endif
        strcpy(board[0], buf);
        for (int i = 1; i <= 4; ++i) {
            fgets(buf, MAX, stdin);
            strcpy(board[i], buf);
        }

        bool found = false;
        for (int i = 0; !found && i < 5; ++i) {
            for (int k = 0; !found && k < 5; ++k) {
                if (board[i][k] == ' ') {
                    px = i;
                    py = k;
                    found = true;
                    break;
                }
            //    printf("%c", board[i][k]);
            }
            //printf("\n");
        }

        // print_board();
        // assert(found);

        char c;
        bool valid = true;
        while ((c = getchar()) != '0') {
            // printf("cmd = %c", c);
            if (valid) {
                int dx = 0, dy = 0;
                if (c == 'A') {
                    valid = !(px == 0);
                    dx -= 1;
                } else if (c == 'B') {
                    valid = !(px == 4);
                    dx += 1;
                } else if (c == 'L') {
                    valid = !(py == 0);
                    dy -= 1;
                } else if (c == 'R') {
                    valid = !(py == 4);
                    dy += 1;
                } else if (c != '\n' && c != ' '){
                    valid = false;
                } 
                if (valid) {
                    std::swap(board[px][py], board[px+dx][py+dy]);
                    px = px + dx;
                    py = py + dy;
                }
            }
        }
        getchar(); // remove the last newline character
        if (posPuzzle != 1)
            printf("\n");
        printf("Puzzle #%d:\n", posPuzzle++);
        if (valid) {
            for (int i = 0; i < 5; ++i) {
                for (int k = 0; k < 5; ++k) {
                    if (k != 0)
                        printf(" ");
                    printf("%c", board[i][k]);
                    if (k == 4)
                        printf("\n");
                }
            }
        } else {
            printf("This puzzle has no final configuration.\n");
        }
//        printf("End one\n");
    }
    return 0;
}
