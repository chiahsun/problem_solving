#include <cstdio>
#include <cstring>
#include <cassert>
#include <list>
#include <vector>

struct HashSet {
    typedef std::list<int> list_type;
    std::vector<list_type> _vecList;
    HashSet(int size) { 
        if (size < 2) size = 4; 
        _vecList.resize(size);
    }
    unsigned int hashCode(unsigned int x) const {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x);
        return x % _vecList.size();
    }
    int count(int x) const {
        int index = hashCode(x);
        for (auto it = _vecList[index].begin(); it != _vecList[index].end(); ++it)
            if (*it == x)
                return 1;
        return 0;
    }
    void insert(int x) {
        if (not count(x)) {
            int index = hashCode(x);
            _vecList[index].insert(_vecList[index].end(), x);
        }
    }
};

bool visited[40][10000];
int initial, target;
int nforbideen;
int get_number() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    return 10*(10*(10*a+b)+c)+d;
}
// 0 1 2 3
int add_digit(int x, int pos, bool reverse = false) {
    assert(pos >= 0 and pos < 4);
    int base[5] = {1, 10, 100, 1000, 10000};
    int cur_base = base[pos];
    int higher_base = base[pos+1];
    int lower = x % cur_base;
    int higher = x - x % higher_base;
    int cur = x % higher_base - lower;
    if (not reverse)
        cur = (cur + cur_base) % higher_base;
    else
        cur = (higher_base + cur - cur_base) % higher_base;
    return cur + lower + higher;
#if 0
    int val = x / cur_base % 10;
    x -= (val * cur_base);
    if (not reverse)
        val = (val + 1) % 10;
    else
        val = (10 + val - 1) % 10;
    x += (val * cur_base);
    return x;
#endif
}
int minus_digit(int x, int pos) { return add_digit(x, pos, true); }

void dfs(int cur, int cur_depth, const int & bound, int & depth, bool & found, const int & target, const HashSet & forbiddens) {
    // printf("%d (%d)\n", cur, cur_depth);
    if (cur_depth != 0 and forbiddens.count(cur))
        return;
    
    if (target == cur) {
        found = true;
        depth = cur_depth;
        return;
    }
    if (visited[cur_depth][cur])
        return;
    // Key: set for 40, not for nodesi after(would be enumerous) to track 40
    for (int i = cur_depth; i <= bound; ++i) 
        visited[i][cur] = true;
    
    if (cur_depth < bound) {
        for (int i = 0; not found and (i < 4); ++i) {
            int next1 = add_digit(cur, i);
            dfs(next1, cur_depth+1, bound, depth, found, target, forbiddens);
            int next2 = minus_digit(cur, i);
            dfs(next2, cur_depth+1, bound, depth, found, target, forbiddens);
        }
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        initial = get_number();
        target = get_number();
        scanf("%d", &nforbideen);
        HashSet forbiddens(nforbideen);
        for (int i = 0; i < nforbideen; ++i)
            forbiddens.insert(get_number());
        int depth = (target == initial) ? 0 : -1;
#if 1 
        if (depth != 0) {
            bool found = false;
            for (int bound=1;bound < 40; ++bound) {
                for (int i = 0; i <= bound; ++i)
                    memset(visited[i], false, sizeof(visited[i]));
                dfs(initial, 0, bound, depth, found, target, forbiddens);
            }
        }
        printf("%d\n", depth);
#endif
    }
    return 0;
}
