#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <queue>

int V[3], D;

struct Lit {
    int _water[3];
    int _cost;
    Lit(int x, int y, int z, int cost) {
        _water[0] = x;
        _water[1] = y;
        _water[2] = z;
        _cost = cost;
    }
    Lit(int water[3], int cost) {
        memcpy(_water, _water, sizeof(int) * 3) ;
        _cost = cost;
    } 
    int getWater(int pos) const { assert(pos >= 0 and pos < 3); return _water[pos]; }
    int getCost() const { return _cost; }
};

Lit pour(Lit x, int from, int to) {
    Lit res(x);
    int max_transfer = std::min(x._water[from], V[to]-x._water[to]);
    res._water[from] -= max_transfer;
    res._water[to] += max_transfer;
    res._cost += max_transfer;
    return res;
}

struct CostCompare {
    bool operator () (const Lit & lhs, const Lit & rhs) const {
        return lhs.getCost() > rhs.getCost();
    }
};

int visited[200+5][200+5];

void update_cost(int w, int c, int & cl_w, int & cl_c) {
    if (w <= D) {
        if (w == cl_w) cl_c = std::min(cl_c, c);
        else if (w > cl_w) { cl_w = w; cl_c = c; }
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d%d%d", V, V+1, V+2, &D);
        memset(visited, -1, sizeof(visited));
        Lit x(0, 0, V[2], 0);
        int closest_min = (V[2] <= D ? V[2] : 0);
        int closest_cost = 0;
        visited[0][0] = 0;
        std::priority_queue<Lit, std::vector<Lit>, CostCompare> q;
        q.push(x);
        while (not q.empty()) {
            Lit f = q.top(); q.pop();
            for (int i = 0; i < 3; ++i)
                for (int k = 0; k < 3; ++k) {
                    if (i != k) {
                        Lit a = pour(f, i, k);
                        int w0 = a.getWater(0);
                        int w1 = a.getWater(1);
                        int w2 = a.getWater(2);
                        int c = a.getCost();
                        if (visited[w0][w1] < 0 or visited[w0][w1] > c) {
                            visited[w0][w1] = c;
                            q.push(a);
                        }
                        update_cost(w0, c, closest_min, closest_cost);
                        update_cost(w1, c, closest_min, closest_cost);
                        update_cost(w2, c, closest_min, closest_cost);
                    }
                }
        }
        printf("%d %d\n", closest_cost, closest_min);
    }
    return 0;
}
