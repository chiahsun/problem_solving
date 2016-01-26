#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

std::map<int, std::vector<int> > mapSibling;
const int M = 10000+5;
bool fall[M];

void dfs(int knock, int & nfall) {
    fall[knock] = true;
    ++nfall;
    for (const auto & x : mapSibling[knock]) {
        if (not fall[x])
            dfs(x, nfall);
    }
}

int main() {
    int nCase, nDomino, nSibling, nKnock;
    int from, to, knock;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d%d", &nDomino, &nSibling, &nKnock);
        mapSibling.clear();
        while (nSibling--) {
            scanf("%d%d", &from, &to);
            mapSibling[from].push_back(to);
        }
        memset(fall, false, sizeof(bool) * (nDomino+1));
        int nfall = 0;
        while (nKnock--) {
            scanf("%d", &knock);
            if (not fall[knock])
                dfs(knock, nfall);
        }
        printf("%d\n", nfall);
    }
    return 0;
}
