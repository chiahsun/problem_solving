#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>

typedef std::map<unsigned long long, unsigned long long> Node;

Node read_expr();

Node read_node() {
    int x;
    scanf("%d", &x);
    return Node({std::make_pair(0, 1), std::make_pair(x, 0)});
}

Node read_tree() {
    getchar();
    Node m1 = read_expr();
    getchar();
    Node m2 = read_expr();
    getchar();

    Node m = {std::make_pair(0, m1[0] + m2[0])};
    for (auto it = ++m1.begin(); it != m1.end(); ++it) {
        unsigned long long x = it->first;
        if (m2.count(x)) {
            m.insert(std::make_pair(x * 2, m1[x] + m2[x]));
        } else {
            m.insert(std::make_pair(x * 2, m1[x] + m2[0]));
        }
    }
    for (auto it = ++m2.begin(); it != m2.end(); ++it) {
        unsigned long long x = it->first;
        if (not m1.count(x)) {
            m.insert(std::make_pair(x * 2, m1[0] + m2[x]));
        }
    }
    return m;
}

Node read_expr() {
    
    char c; 
    while ((c = getchar()) == ' ' or c == '\n') { }
    ungetc(c, stdin);
    if (c == '[') {
        return read_tree();
    } else {
        return read_node();
    }
}

int main() {
    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        Node n = read_expr();
        unsigned long long val = n[0];
        for (const auto & pr : n) {
            val = std::min(val, pr.second);
        }
        printf("%llu\n", val);
    }

    return 0;
}
