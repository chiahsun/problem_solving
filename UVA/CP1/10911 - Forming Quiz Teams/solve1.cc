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
double square(double x) { return x * x; }

double get_cost(int cur, int other) {
    return sqrt(square(stu[cur]._x-stu[other]._x) + square(stu[cur]._y-stu[other]._y));
}

void match(int cur, int other, double cost, int nvisited, double & bound) {
    visited[cur] = visited[other] = true;
    cost += get_cost(cur, other);
    nvisited += 2;

//    if (cost > bound)
//        return;
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
