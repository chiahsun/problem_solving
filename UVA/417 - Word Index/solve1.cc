#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

struct Now { 
    std::string _s;
    int _index;
    Now(std::string s, int idx) : _s(s), _index(idx) { }
    Now(char c, int idx) : _index(idx) { _s.push_back(c); }
    bool operator < (const Now & rhs) const { return _s < rhs._s; }
};
int main() {
    std::queue<std::string> q;
    std::vector<Now> v;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string s; s.push_back(c);
        q.push(s);
    }

    int cnt = 1;
    while (not q.empty()) {
        std::string cur = q.front(); q.pop();
        v.push_back(Now(cur, cnt++));
        if (cur.size() < 5)
            for (char c = cur.back()+1; c <= 'z'; ++c) 
                q.push(cur+c);
    }

    std::sort(v.begin(), v.end());
    char buf[10];
    while (scanf("%s", buf) == 1) {
        auto it = std::lower_bound(v.begin(), v.end(), Now(buf, 0));
        int index = (it != v.end() and it->_s == buf) ? it->_index : 0;
        printf("%d\n", index);
    }

    return 0;
}
