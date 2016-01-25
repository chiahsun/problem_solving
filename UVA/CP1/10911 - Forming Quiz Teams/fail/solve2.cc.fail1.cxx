#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int N;
char name[1000];

struct Student { int _x, _y; };

const int M = 8*2 + 5;
Student stu[M];
bool visited[M];
int prev[M];
double square(double x) { return x * x; }

double get_cost(int cur, int other) {
    return sqrt(square(stu[cur]._x-stu[other]._x) + square(stu[cur]._y-stu[other]._y));
}

bool overlap(int x1, int x2, int y1, int y2) {
#if 1 
    int max_x = std::max(x1, x2);
    int min_x = std::min(x1, x2);
    int max_y = std::max(y1, y2);
    int min_y = std::min(y1, y2);
    if (min_y >= max_x) return false;
    if (max_y <= min_x) return false;
    return true;
#endif
}

bool cross_line(int s1, int s2, int s3, int s4) {
    int x1 = stu[s1]._x, y1 = stu[s1]._y;
    int x2 = stu[s2]._x, y2 = stu[s2]._y;
    int x3 = stu[s3]._x, y3 = stu[s3]._y;
    int x4 = stu[s4]._x, y4 = stu[s4]._y;

    return overlap(x1, x2, x3, x4) and overlap(y1, y2, y3, y4);
}

void match(int cur, int other, double cost, int nvisited, double & bound) {

    for (int i = 0; i < nvisited; i+=2) {
        if (cross_line(prev[i], prev[i+1], cur, other))
            return;
    }

    prev[nvisited] = cur;
    prev[nvisited+1] = other;
    visited[cur] = visited[other] = true;
    cost += get_cost(cur, other);
    nvisited += 2;

//    printf("now %d and %d (%d)\n", cur, other, nvisited);
    if (nvisited == N) {
        bound = std::min(bound, cost);
//        printf("cost:%.2f\n", cost);
    } else if (cost <= bound) {
        for (int i = cur+1; i < N; ++i) {
            if (not visited[i]) {
                for (int k = i+1; k < N; ++k) {
                    if (not visited[k])
                        match(i, k, cost, nvisited, bound);
                }
            }
        }
    }
    visited[cur] = visited[other] = false;
}
// XXX: sort according to ...
int main() {
    int posCase = 1;
    while (scanf("%d", &N) == 1 and N) {
        N *= 2;
        for (int i = 0; i < N; ++i)
            scanf("%s%d%d", name, &stu[i]._x, &stu[i]._y);
        double cost = 0, bound = 1000*2*8+5;
        memset(visited, false, sizeof(visited));
        int nvisited = 0;
        for (int k = 1; k < N; ++k) {
            match(0, k, cost, nvisited, bound);
        }
        printf("Case %d: %.2f\n", posCase++, bound);
    }
    return 0;
}
