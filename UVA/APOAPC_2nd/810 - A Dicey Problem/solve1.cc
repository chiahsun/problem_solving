#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

const bool debug = false;

char maze_name[20+5];

int nRow, nCol, startX, startY, startTop, startFront;

int corner_rotate[8][3] = 
  { {5, 3, 1}
  , {5, 6, 3}
  , {5, 4, 6}
  , {5, 1, 4}
  , {2, 6, 4}
  , {2, 3, 6}
  , {2, 1, 3}
  , {2, 4, 1} };
int die[7][7];

void elaborate() {
    memset(die, -1, sizeof(die));
    for (int d = 0; d < 8; ++d) {
        for (int i = 0; i < 3; ++i) {
            int top = corner_rotate[d][i % 3];
            int front = corner_rotate[d][(i+1) % 3];
            int left = corner_rotate[d][(i+2) % 3];
    //        printf("die[%d][%d] = %d\n", top, front, left);
            die[top][front] = left;
        }
    }
}

void turn_right(int & top, int & front) {
    top = die[top][front];
}

void turn_left(int & top, int & front) {
    turn_right(top, front);
    top = 7 - top;
}

void turn_forward(int & top, int & front) {
    std::swap(top, front);
    top = 7 - top;
}

void turn_backward(int & top, int & front) {
    std::swap(top, front);
    front = 7 - front;
}

typedef void (*move_function)(int & top, int & front);

move_function move_table[4] = {turn_right, turn_left, turn_forward, turn_backward};

const int M = 10 + 5;
int maze[M][M];
bool visited[M][M][7][7];
int next[M][M][7][7][4];
const int WILD = -1;

char c;

void print_solution(int x, int y, int top, int front) {
    int cnt = 0;
    printf("  ");
    bool end = false;
    do {
        int* p = next[x][y][top][front];
        printf("(%d,%d)", x+1, y+1);
        if (end)
            break;
        x = p[0];
        y = p[1];
        top = p[2]; 
        front = p[3]; 
        if (x != -1)
            printf(",");
        if (cnt == 8 and x != -1) {
            printf("\n  ");
            cnt = 0;
        } else {
            ++cnt;
        }
        if (x == startX and y == startY)
            end = true;
    } while (1);
    printf("\n");
}

bool solve(const int & posx, const int & posy, const int & top, const int & front) {
    int dx[4] = {0,  0,  1,  -1};
    int dy[4] = {1,  -1, 0,  0};
   
    if (debug) 
        printf("visit (%d, %d) with (%d, %d)\n", posx, posy, top, front);

    if (visited[posx][posy][top][front])
        return false;
    visited[posx][posy][top][front] = true;
    
    for (int i = 0; i < 4; ++i) {
        int x = posx + dx[i];
        int y = posy + dy[i];
        if ( x >= 0 and x < nRow and y >= 0 and y < nCol 
        and (maze[x][y] == top or maze[x][y] == WILD) ) {
            int new_top = top;
            int new_front = front;
            move_table[i](new_top, new_front);
            if ((x == startX and y == startY) or solve(x, y, new_top, new_front)) { 
                int res[4] = {x, y, new_top, new_front};
                for (int k = 0; k < 4; ++k)
                    next[posx][posy][top][front][k] = res[k];
                return true;
            }
        }
    }
    return false;
}

int main() {
    elaborate();

    while (scanf("%[^\n]", maze_name) == 1 && strcmp(maze_name, "END") != 0) {
        printf("%s\n", maze_name);
        getchar();
        scanf("%d%d%d%d%d%d", &nRow, &nCol, &startX, &startY, &startTop, &startFront);

        for (int i = 0; i < nRow; ++i)
            for (int k = 0; k < nCol; ++k) {
                scanf("%d", &maze[i][k]);
            }
        while ((c = getchar()) == ' ') { }
        ungetc(c, stdin);
        while ((c = getchar()) == '\n') { }
        ungetc(c, stdin);
#if 0
        for (int i = 0; i < nRow; ++i) {
            for (int k = 0; k < nCol; ++k) {
                printf("%d ", maze[i][k]);
            }
            printf("\n");
        }
#endif

        memset(visited, false, sizeof(visited));
        --startX; --startY;
        bool found = solve(startX, startY, startTop, startFront);
        if (found)
            print_solution(startX, startY, startTop, startFront);
        else
            printf("  No Solution Possible\n");
    }
    return 0;
}
