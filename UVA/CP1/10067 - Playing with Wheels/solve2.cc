#include <cstdio>
#include <cstring>
#include <cassert>
#include <list>
#include <vector>
#include <queue>

bool enqued[10000];
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
}
int minus_digit(int x, int pos) { return add_digit(x, pos, true); }


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
        int depth = (initial == target) ? 0 : -1;
        if (depth != 0) {
            std::queue<int> q[2];
            q[0].push(initial);
            memset(enqued, false, sizeof(enqued));
            enqued[initial] = true;
            int cur_depth = 0;
            bool found = false;
            while (not q[0].empty() or not q[1].empty()) {
                std::queue<int> & qnow = q[0].empty() ? q[1] : q[0];
                std::queue<int> & qnext = q[0].empty() ? q[0] : q[1];
                while (not qnow.empty()) {
                    int f = qnow.front(); qnow.pop();
                    if (f == target) {
                        found = true;
                        depth = cur_depth;
                        break;
                    }
                    if (f == initial or (not forbiddens.count(f))) {
                        for (int i = 0; i < 4; ++i) {
                            int next1 = add_digit(f, i);
                            if (not enqued[next1])
                                qnext.push(next1);
                            int next2 = minus_digit(f, i);
                            if (not enqued[next2])
                                qnext.push(next2);
                            enqued[next2] = enqued[next1] = true;
                        }
                    }
                }
                if (found)
                    break;
                ++cur_depth;
            }
        }
        printf("%d\n", depth);
    }
    return 0;
}
