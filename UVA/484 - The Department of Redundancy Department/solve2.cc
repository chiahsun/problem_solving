#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> m;
    std::vector<int> v;
    int x;
    while (scanf("%d", &x) == 1) { 
        if (not m.count(x)) {
            v.push_back(x);
            m.insert(std::make_pair(x, 0));
        }
        ++m[x];
    }
    for (const auto a : v)
        printf("%d %d\n", a, m[a]);
    return 0;
}
