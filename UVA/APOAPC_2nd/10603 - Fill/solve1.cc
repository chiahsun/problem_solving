#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

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
    bool operator < (const Lit & rhs) const {
        for (int i = 0; i < 3; ++i) {
            if (_water[i] != rhs._water[i])
                return _water[i] < rhs._water[i];
        }
        return false;
    }
    int getWater(int pos) const { assert(pos >= 0 and pos < 3); return _water[pos]; }
    int getCost() const { return _cost; }
};

struct WaterCostCompare {
    bool operator () (const std::pair<int, int> & lhs, const std::pair<int, int> & rhs) const {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    }
};

void print_lit(const Lit & lit) {
    for (int i = 0; i < 3; ++i)
        printf("%d ", lit.getWater(i));
    printf(" (%d)\n", lit.getCost());
}

bool check(const Lit & lit) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) 
        if (not (lit.getWater(i) >= 0 and lit.getWater(i) <= V[i])) {
            ok = false;
        }
    if (not(lit.getCost() >= 0))
        ok = false;
    if (not ok) {
        print_lit(lit);
    }
    return ok;
}

Lit pour(Lit x, int from, int to) {
    assert(check(x));
    Lit res(x);
    int max_transfer = std::min(x._water[from], V[to]-x._water[to]);
    res._water[from] -= max_transfer;
    res._water[to] += max_transfer;
    res._cost += max_transfer;
    assert(check(res));
    return res;
}


int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        std::set<Lit> sLit;
        scanf("%d%d%d%d", V, V+1, V+2, &D);
        Lit x(0, 0, V[2], 0);
        sLit.insert(x);
        std::queue<Lit> q;
        q.push(x);
        while (not q.empty()) {
            Lit f = q.front(); q.pop();
            assert(check(f));
            for (int i = 0; i < 3; ++i)
                for (int k = 0; k < 3; ++k) {
                    if (i != k) {
                        Lit a = pour(f, i, k);
                        assert(check(a));
                        if (not sLit.count(a) or sLit.find(a)->_cost > a._cost) {
                            if (sLit.count(a) and sLit.find(a)->_cost > a._cost) {
                                sLit.erase(a);
                            } 
                            sLit.insert(a);
                            q.push(a);
                        }
#if 0
                        printf("In set\n");
                        for (auto & lit : sLit)
                            print_lit(lit);
#endif
                    }
                }
        }
        std::vector<std::pair<int, int> > vecWaterAndCost;
        for (const auto & lit : sLit) {
            for (int i = 0; i < 3; ++i) {
                int w = lit.getWater(i);
                int c = lit.getCost();
                assert(w >= 0 and w <= V[i]);
                assert(c >= 0);
                vecWaterAndCost.push_back(std::make_pair(w, c));
            }
        }
        std::sort(vecWaterAndCost.begin(), vecWaterAndCost.end(), WaterCostCompare());
#if 0
        for (int i = 0; i < vecWaterAndCost.size(); ++i)
            printf("%d %d\n", vecWaterAndCost[i].first, vecWaterAndCost[i].second);
        printf("D:%d\n", D);
#endif
//        printf("search %d\n", D);
        auto it = std::lower_bound(vecWaterAndCost.begin(), vecWaterAndCost.end(), std::make_pair(D, -1));
        if (it->first != D and it != vecWaterAndCost.begin()) {
            --it;
//            printf("search %d\n", it->first);
            it = std::lower_bound(vecWaterAndCost.begin(), vecWaterAndCost.end(), std::make_pair(it->first, -1));
        }
        printf("%d %d\n", it->second, it->first);
    }
    return 0;
}
