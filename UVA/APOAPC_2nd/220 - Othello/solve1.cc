#include <cstdio>
#include <cstring>

#include <utility>
#include <algorithm>

const bool debug = false;

// case:
//    black has no moves but it's black's turn
//    after update white
//    should make the current palyer black again

const int N = 8;
const int MAX = 8+1;
char board[9][9];

char buf[20];
char cmd[5];

bool availb[MAX][MAX];
bool availw[MAX][MAX];

struct Avail{
    int _x, _y;
    Avail() { }
    Avail(int x, int y) : _x(x), _y(y) {}
    int getX() const { return _x; }
    int getY() const { return _y; }
    bool operator < (const Avail & rhs) const { return _x < rhs._x or ((_x == rhs._x) and (_y < rhs._y)); }
};
Avail avail_buffer[N*N];

const char BLACK = 'B';
const char WHITE = 'W';
const char EMPTY = '-';

void print_board() {
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= N; ++k) {
            printf("%c", board[i][k]);
        }
        printf("\n");
    }
}

void print_avail(char now) {
    bool (*pavail)[MAX] = (now == BLACK) ? availb : availw;
    printf("Current avail:\n");
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= N; ++k) {
            printf("%c", pavail[i][k] ? 'T' : '-');
        }
        printf("\n");
    }
}

bool is_in_range(int x, int y) { return (x >= 1) and (x <= N) and (y >= 1) and (y <= N); }

bool is_avaialable(char me, int availx, int availy, int dx, int dy) {
    char other = (me == BLACK) ? WHITE : BLACK;
    int x = availx + dx;
    int y = availy + dy;
    
    if (is_in_range(x, y) and (board[x][y] == other)) {
        do {
            x += dx;
            y += dy;
        } while (is_in_range(x, y) and board[x][y] == other);

        return (is_in_range(x, y) and board[x][y] == me);
    }
    return false;
}

int get_all_available(char me) {
    bool (*pavail)[MAX] = (me == BLACK) ? availb : availw;

    char other = (me == BLACK) ? WHITE : BLACK;
    memset(pavail, 0, sizeof(bool) * MAX * MAX);
    int cnt_avail = 0;
    for (int x = 1; x <= N; ++x)
        for (int y = 1; y <= N; ++y) {
            if (!pavail[x][y] && board[x][y] == EMPTY) {
                const int NUM_D = 8;
                const int dx[NUM_D] = {1,  1,  0, -1, -1, -1, 0, 1};
                const int dy[NUM_D] = {0, -1, -1, -1,  0,  1, 1, 1};

                for (int posd = 0; posd < NUM_D; ++posd) {
                    if (is_avaialable(me, x, y, dx[posd], dy[posd])) {
                        pavail[x][y] = true;
                        avail_buffer[cnt_avail] = Avail(x, y);
                        ++cnt_avail;
                        break;
                    }

                }
                
            }
        }

    return cnt_avail;
}

void change_player(char & cur_player) {
    cur_player = (cur_player == BLACK) ? WHITE : BLACK;
}

void play_a_move(char me, int availx, int availy, int & cnt_cur, int & cnt_other) {
    const int NUM_D = 8;
    const int dx[NUM_D] = {1,  1,  0, -1, -1, -1, 0, 1};
    const int dy[NUM_D] = {0, -1, -1, -1,  0,  1, 1, 1};

    for (int posd = 0; posd < NUM_D; ++posd) {
        int cur_dx = dx[posd];
        int cur_dy = dy[posd];

        if (is_avaialable(me, availx, availy, cur_dx, cur_dy)) {
            for (int x = availx+cur_dx, y = availy+cur_dy; board[x][y] != me; x += cur_dx, y += cur_dy) {
                board[x][y] = me;
                ++cnt_cur;
                --cnt_other;
            }
        } 
    }
    if (board[availx][availy] != EMPTY)
        --cnt_other;
    board[availx][availy] = me;
    ++cnt_cur;
}


int main() {
    int nCase;
    scanf("%d", &nCase);
       
    while (nCase--) {
        int nBlack = 0, nWhite = 0; 
        for (int i = 0; i < N; ++i) {
            scanf("%s", buf);
            strncpy(board[i+1]+1, buf, N);
            for (int k = 0; k < N; ++k) {
                if (buf[k] == BLACK) ++nBlack;
                else if (buf[k] == WHITE) ++nWhite;
            }
        }
        if (debug) {
            printf("Current board:\n");
            print_board();
        }
        getchar();
        char curPlayer;
        scanf("%c", &curPlayer);
        if (debug)
            printf("Cur player: %c\n", curPlayer);
        getchar();
        while (scanf("%s", cmd)) {
            if (debug)
                printf("Cur command: %s\n", cmd);
            if (cmd[0] == 'Q') {
                print_board();
                if (nCase)
                    printf("\n");
                break;
            } else if (cmd[0] == 'L') {
                int navail = get_all_available(curPlayer);
                // print_avail(curPlayer);
                if (navail > 0) {
                    std::sort(avail_buffer, avail_buffer+navail);
                    for (int i = 0; i < navail; ++i) {
                        if (i != 0)
                            printf(" ");
                        printf("(%d,%d)", avail_buffer[i].getX(), avail_buffer[i].getY());
                    }
                    printf("\n");
                } else {
                    printf("No legal move.\n");
                }
            } else if (cmd[0] == 'M') {
                int navail = get_all_available(curPlayer);
                if (navail == 0)
                    change_player(curPlayer);
                if (curPlayer == BLACK)
                    play_a_move(curPlayer, cmd[1]-'0', cmd[2]-'0', nBlack, nWhite);
                else
                    play_a_move(curPlayer, cmd[1]-'0', cmd[2]-'0', nWhite, nBlack);
                change_player(curPlayer);

                printf("Black - %2d White - %2d\n", nBlack, nWhite);
            }
        }
    }

    return 0;
}
