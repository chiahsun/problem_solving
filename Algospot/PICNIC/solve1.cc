#include <cstdio>
#include <vector>

const bool debug = false;

const int M = 10;
bool visited[M];
std::vector<std::vector<int> > relation;

void dfs(int cur, size_t nvisited, int & cnt) {
    visited[cur] = true;

    for (auto next : relation[cur]) {
        if (not visited[next]) {
            if (nvisited == relation.size()-2) {
                ++cnt;
                break;  
            } else {
                visited[next] = true;
                if (debug) {
                    for (size_t i = 0; i < nvisited; ++i) printf(" ");
                    printf("%d -> %d", cur, next);
                    printf("\n");
                }
                for (size_t i = cur+1; i < relation.size(); ++i) {
                    if (not visited[i]) {
                        dfs(i, nvisited+2, cnt);
                        break;
                    }
                }
                visited[next] = false;
            }
        }
    }
    visited[cur] = false;
}

int main() {
    int nCase, nPeople, nRelation;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &nPeople, &nRelation);
        relation.clear();
        relation.resize(nPeople);

        for (int i = 0; i < nRelation; ++i) {
            int from, to;
            scanf("%d%d", &from, &to);
            relation[from].push_back(to);
            relation[to].push_back(from);
        }
        int cnt = 0;
        dfs(0, 0, cnt);
        printf("%d\n", cnt);
    }
    return 0;
}
