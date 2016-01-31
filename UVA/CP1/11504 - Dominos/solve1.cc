#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

const bool debug = false;

const int M = 100000+5;
std::vector<std::vector<int> > edges;

bool visited[M];
const int NOT_IN_STACK = M + 10;
int in_stack[M];
int scc[M];
int indegree[M];

int find_scc(int cur, std::stack<int> & parents) {
    visited[cur] = true;
    int cur_pos = in_stack[cur] = parents.size();
    parents.push(cur);

    int top_parent_pos = NOT_IN_STACK;
    for (auto next : edges[cur]) {
        int pos_in_stack;
        if (not visited[next]) {
            pos_in_stack = find_scc(next, parents);
        } else {
            pos_in_stack = in_stack[next];
        }
        top_parent_pos = std::min(top_parent_pos, pos_in_stack);
    }
    if (top_parent_pos == cur_pos) {
        if (debug)
            printf("find SCC : ");
        while (parents.size() != cur_pos) {
            int t = parents.top(); parents.pop();
            in_stack[t] = NOT_IN_STACK;
            scc[t] = cur;
            if (debug)
                printf(" %d", t);
        }
        if (debug)
            printf("\n");
        return NOT_IN_STACK;
    }
    return top_parent_pos; 
}

int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nNode, nEdge;
        scanf("%d%d", &nNode, &nEdge);

        edges.clear();
        edges.resize(nNode+1);
        for (int posEdge = 0; posEdge < nEdge; ++posEdge) {
            int from, to;
            scanf("%d%d", &from, &to);
            edges[from].push_back(to);
        }
        memset(visited, false, sizeof(bool) * (nNode+1));
        for (int i = 1; i <= nNode; ++i) {
            in_stack[i] = NOT_IN_STACK;
            scc[i] = i;
            indegree[i] = 0;
        }
        std::stack<int> parents;
        for (int i = 1; i <= nNode; ++i) {
            if (not visited[i]) {
                find_scc(i, parents);
            }
        }
        
        for (int i = 1; i <= nNode; ++i) {
            for (auto next : edges[i]) {
                if (scc[next] != scc[i])
                    ++indegree[scc[next]];
            }
        }
        int nhead = 0;
        for (int i = 1; i <= nNode; ++i) {
            if (scc[i] == i and indegree[i] == 0) {
                ++nhead;
            }
        }
        printf("%d\n", nhead);
    }
    return 0;
}
