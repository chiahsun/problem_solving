#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <utility>

const bool debug = false;

bool is_in_palace(int x, int y) {
    return (abs(x - 2) <= 1) and (abs(y - 5) <= 1);
}

void read_space_and_newline() {
    char c;
    while ((c = getchar()) == ' ' or c == '\b' or c == '\n') { };
    ungetc(c, stdin);

}


bool reds_on_board[12][12];

// one chess on from and one chess on to
int is_intervened_by_x(int from, int to, int y) {
    if (from > to)
        std::swap(from, to);
    int cnt = 0; 
    for (int i = from+1; i < to; ++i) {
        if (reds_on_board[i][y])
            ++cnt;
    }
    return cnt;
}

int is_intervened_by_y(int from, int to, int x) {
    if (from > to)
        std::swap(from, to);
    int cnt = 0;
    for (int i = from+1; i < to; ++i) {
        if (reds_on_board[x][i])
            ++cnt;
    }
    return cnt;
}




struct Red {
    char _type;
    int _x, _y;
    Red() { }
    Red(char type, int x, int y) : _type(type), _x(x), _y(y) { }
    char getType() const { return _type; }
    int getX() const { return _x; }
    int getY() const { return _y; }
    bool isReachable(int generalx, int generaly) {
        if (getX() == generalx and getY() == generaly)
            return false; // taken by general
        if (getType() == 'G') {
            if (getY() == generaly) {
                return (is_intervened_by_x(generalx, getX(), getY()) == 0); 
            }
            return false;
        } else if (getType() == 'R') {
            if (getX() == generalx) {
                return (is_intervened_by_y(generaly, getY(), getX()) == 0); 
            } else if (getY() == generaly) {
                return (is_intervened_by_x(generalx, getX(), getY()) == 0); 
            }
            return false;
        } else if (getType() == 'H') {
            int dx[8]     = {1, 1, 2, 2, -1, -1, -2, -2};
            int dy[8]     = {2, -2, 1, -1, 2, -2, 1, -1};
            int hob_dx[8] = {0, 0, 1, 1, 0, 0, -1, -1};
            int hob_dy[8] = {1, -1, 0, 0, 1, -1, 0, 0}; 
            for (int i = 0; i < 8; ++i) {
                int nextx = getX() + dx[i];
                int nexty = getY() + dy[i];
                if (generalx == nextx && generaly == nexty) {
                    int hobx = getX() + hob_dx[i];
                    int hoby = getY() + hob_dy[i];
                    return !reds_on_board[hobx][hoby];
                }
            }
            return false;
        } else if (getType() == 'C') {
            if (getX() == generalx) {
                return (is_intervened_by_y(generaly, getY(), getX()) == 1); 
            } else if (getY() == generaly) {
                return (is_intervened_by_x(generalx, getX(), getY()) == 1); 
            }
            return false;
            
        }
        assert(0);
    }
};

Red reds[7+3];


bool is_check_mate(int generalx, int generaly, int nred) {
    for (int pos_red = 0; pos_red < nred; ++pos_red) {
        if (reds[pos_red].isReachable(generalx, generaly)) {
            if (debug)
                printf("general[%d][%d] checked by %c[%d][%d]\n", generalx, generaly, reds[pos_red].getType(), reds[pos_red].getX(), reds[pos_red].getY());
            return true;
        }
    }
    return false;
}

int main() {
    int nred, generalx, generaly;
    while (scanf("%d%d%d", &nred, &generalx, &generaly) == 3 && nred) {
        if (debug)
            printf("%d general %d %d\n", nred, generalx, generaly);
        read_space_and_newline();

        memset(reds_on_board, 0, sizeof(reds_on_board));

        for (int posRed = 0; posRed < nred; ++posRed) {
            char red_type;
            int posx, posy;
            scanf("%c%d%d", &red_type, &posx, &posy);
            read_space_and_newline();
            if (debug)
                printf("red %c %d %d\n", red_type, posx, posy);
            reds[posRed] = Red(red_type, posx, posy);
            reds_on_board[posx][posy] = true;
        }

        // case: flying general of red on black
        // case: one at left of general that can be taken by general
        //       but two cases
        //       w/wo covered by other reds
        
        int dx[4] = {1, -1, 0,  0};
        int dy[4] = {0,  0, 1, -1};
        bool escape = false;
        for (int posRed = 0; posRed < nred; ++posRed) {
            if (reds[posRed].getType() == 'G') {
                if (reds[posRed].isReachable(generalx, generaly)) {
                    escape = true;
                    break;
                }
            }
        }

        if (!escape) {
            for (int i = 0; i < 4; ++i) {
                int x = generalx + dx[i];
                int y = generaly + dy[i];
                //            printf("now [%d][%d]\n", x, y);
                if (is_in_palace(x, y) && !is_check_mate(x, y, nred)) {
                    escape = true;
                    break;
                }
            }
        }
        if (!escape) 
            printf("YES\n");
        else
            printf("NO\n");

        read_space_and_newline();
    }

    return 0;
}
