#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <queue>

const bool debug = false;

char maze_name[50];
char buf[50];
const int M = 9+5;

enum { N = 0, E, S, W};
enum { R = 0, F, L};

int getDirId(char c) {
    switch(c) {
        case 'N': return N;
        case 'E': return E;
        case 'S': return S;
        case 'W': return W;
        default: break;
    }
    assert(0);
    return 0;
}

int getFaceId(char c) { 
    switch(c) {
        case 'R': return R;
        case 'F': return F;
        case 'L': return L;
        default: break;
    }
    assert(0);
    return 0;
}

#define MN {-1,  0, 0}
#define ME { 0,  1, 1}
#define MS { 1,  0, 2}
#define MW { 0, -1, 3}
const int change_dir[4][3][3] =
 {  {ME, MN, MW}
  , {MS, ME, MN}
  , {MW, MS, ME}
  , {MN, MW, MS}
 };
#undef MN 
#undef ME
#undef MS 
#undef MW 

char maze[M][M][4][4];
bool visited[M][M][4];
int from[M][M][4][3];

char strDir[4] = {'N', 'E', 'S', 'W'};
struct Man {
    int _x, _y;
    int _dir;
    explicit Man(int x, int y, int dir) : _x(x), _y(y), _dir(dir) { }
    std::string toString() const {
        assert(_dir >=0 and _dir < 4);
        return std::string("(") + std::to_string(_x) + ", " + std::to_string(_y) + ", " 
            + strDir[_dir] + ")\n";
    }
    int getX() const { return _x; }
    int getY() const { return _y; }
    int getDir() const { return _dir; }
};

std::vector<Man> makeStep(const Man & man, char* face) {
    std::vector<Man> v;
    int x = man.getX();
    int y = man.getY();
    int dir = man.getDir();
    for (int i = 0; i < strlen(face); ++i) {
        int faceId = getFaceId(face[i]);
        int dx = change_dir[dir][faceId][0];
        int dy = change_dir[dir][faceId][1];
        int new_dir = change_dir[dir][faceId][2];
        assert(new_dir >=0 and new_dir < 4);
        v.push_back(Man(x+dx, y+dy, new_dir));
    }
    return v;
}

void update_from(int newx, int newy, int newDir, int oldx, int oldy, int oldDir) {
   from[newx][newy][newDir][0] = oldx;
   from[newx][newy][newDir][1] = oldy;
   from[newx][newy][newDir][2] = oldDir;
}
void solve( std::vector<std::pair<int, int> > & vecSteps
          , int start_x, int start_y, int start_dir
          , int end_x, int end_y) {
      if (debug)
          printf("start_man: %d %d %d\n", start_x, start_y, start_dir);
      Man start_man(start_x, start_y, start_dir);
      char startFace[2] = "F";
      memset(visited, 0, sizeof(visited));
      
      
      bool found = false;
      int foundDir;
      Man first = makeStep(start_man, startFace)[0];
      if (debug)
          printf("first man: %d %d %d\n", first.getX(), first.getY(), first.getDir());
      visited[first.getX()][first.getY()][first.getDir()]  = true;
      update_from(first.getX(), first.getY(), first.getDir(), start_x, start_y, start_dir);
      if (first.getX() == end_x and first.getY() == end_y) {
          foundDir = first.getDir();
          found = true;
          update_from( first.getX(), first.getY(), first.getDir()
                     , start_x, start_y, start_dir);
      }

      if (debug)
          printf("Man: %s\n", first.toString().c_str());

      std::queue<Man> q;
      q.push(first);

      int nStep = 1;
      int nPass = 0; 
      while (not found and !q.empty()) {
          Man f = q.front(); q.pop();
          if (debug)
              printf("Man(f) %d: %s\n", nStep, f.toString().c_str());
          int x = f.getX();
          int y = f.getY();
          int dir = f.getDir();
          std::vector<Man> v = makeStep(f, maze[x][y][dir]);
          for (const Man & man : v) {
              int newx = man.getX();
              int newy = man.getY();
              int newDir = man.getDir();
              if (newx == start_x and newy == start_y and newDir == start_dir)
                  ++nPass;
              if (newx == end_x and newy == end_y) {
                  if (debug)
                      printf("Reach end\n");
                  found = true;
                  update_from(newx, newy, newDir, x, y, dir);
                  foundDir = newDir;
                  break;
              } else {
                  if (not visited[newx][newy][newDir]) {
                      visited[newx][newy][newDir] = true;
                      update_from(newx, newy, newDir, x, y, dir);
                      q.push(man);
                  }
              }
          }
          ++nStep;
      }

      if (debug)
          printf("Build path\n");
      
      if (found) {
          int x = end_x, y = end_y, dir = foundDir;

          while (x != start_x or y != start_y or dir != start_dir or nPass > 0) {
              if (debug)
                  printf("x : %d, y : %d, dir: %d, nPass: %d\n", x, y, dir, nPass);
              vecSteps.push_back(std::make_pair(x, y));
              if (x == start_x and y == start_y and dir == start_dir)
                  --nPass;
              int oldx = from[x][y][dir][0];
              int oldy = from[x][y][dir][1];
              int oldDir = from[x][y][dir][2];
              x = oldx; y = oldy; dir = oldDir;
          }
          vecSteps.push_back(std::make_pair(start_x, start_y));
      }

      if (debug)
           printf("End build\n");
}

int main() {
    while (scanf("%[^\n]", maze_name) == 1 and strcmp(maze_name, "END") != 0) {
        int start_x, start_y, end_x, end_y;
        char start_dir[5];

        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                for (int m = 0; m < 4; ++m)
                    maze[i][k][m][0] = '\0';
        scanf("%d%d%s%d%d", &start_x, &start_y, start_dir, &end_x, &end_y);
        if (debug)
            printf("Start (%d, %d, %c) to (%d, %d)\n", start_x, start_y, start_dir[0], end_x, end_y);
        int x, y;
        while (scanf("%d", &x) == 1 and x != 0) {
            scanf("%d", &y);
            if (debug)
                printf("Node (%d, %d) : ", x, y);
            while (scanf("%s", buf) == 1 and buf[0] != '*') {
                if (debug)
                    printf("%s ", buf);
                strcpy(maze[x][y][getDirId(buf[0])], buf+1);
            }
            if (debug)
                printf("\n");
        }
        scanf("\n");
#if 0
        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                for (int m = 0; m < 4; ++m) {
                    if (maze[i][k][m][0] != '\0') {
                        printf("maze(%d, %d, %d) : %s\n", i, k, m, maze[i][k][m]);
                    }
                }
#endif
#if 1 
        std::vector<std::pair<int, int> > vecSteps;
        solve(vecSteps, start_x, start_y, getDirId(start_dir[0]), end_x, end_y);
        printf("%s\n", maze_name);
        if (vecSteps.size() != 0) {
            int cnt = 0;
            for (int i = vecSteps.size()-1; i >= 0; --i) {
                printf("%s", ((cnt == 0) ? "  " : " "));
                printf("(%d,%d)", vecSteps[i].first, vecSteps[i].second);
                ++cnt;
                if (cnt == 10) {
                    printf("\n");
                    cnt = 0;
                }
            }
            if (cnt != 0)
                printf("\n");
        } else {
            printf("  No Solution Possible\n");
        }
#endif
    }
    return 0;
}
