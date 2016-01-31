#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>

const bool debug = false;

char buf[50], fst_name[50], snd_name[50];

int get_user_id(const std::map<std::string, std::map<std::string, int> > & m) {
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%[A-Za-z], %s", fst_name, snd_name);
    if (not m.count(fst_name))
        printf("fail fst: %s %s\n", fst_name, snd_name);
    if (not m.at(fst_name).count(snd_name))
        printf("fail snd: %s %s\n", fst_name, snd_name);
    return m.at(fst_name).at(snd_name);
}

std::vector<std::vector<int> > edges;

const int M = 1000+5;
int scc[M];
int pos_in_stack[M];
bool visited[M];
const int NOT_IN_STACK = M + 10;

int find_scc(int cur, std::stack<int> & parents) {
    if (debug)
        printf("cur : %d with scc id %d\n", cur, scc[cur]);
    visited[cur] = true;
    int cur_pos = pos_in_stack[cur] = parents.size();
    parents.push(cur);

    int top_parent_pos = cur_pos;
    for (auto next : edges[cur]) {
        if (not visited[next]) {
//            printf("  visit next %d\n", next);
            int pos = find_scc(next, parents);
            if (pos < top_parent_pos) {
                if (debug)
                    printf("at cur %d set top_parent_pos as %d with new visit next %d \n", cur, pos, next);
                top_parent_pos = pos;
            }
        } else {
            if (pos_in_stack[next] < top_parent_pos) {
                if (debug)
                    printf("at cur %d set top_parent_pos as %d with visited next %d\n", cur, pos_in_stack[next], next);
                top_parent_pos = std::min(top_parent_pos, pos_in_stack[next]);
            }
        }
    }
//    printf("top parent pos:%d\n", top_parent_pos);

    if (top_parent_pos == cur_pos) {
        while (parents.size() != cur_pos) {
            int t = parents.top(); parents.pop();
            scc[t] = cur;
            pos_in_stack[t] = NOT_IN_STACK;
            if (debug)
                printf("set %d with scc %d\n", t, cur);
        }
        return NOT_IN_STACK;
    }
    return top_parent_pos;
}

int main() {
    int nPeople, nRelation;
    while (fgets(buf, sizeof(buf), stdin) and sscanf(buf, "%d%d", &nPeople, &nRelation) == 2 and nPeople) {
        // id start from 1
        std::map<std::string, std::map<std::string, int> > mapNameToId;
        edges.clear(); edges.resize(nPeople+1);
        for (int posPeople = 1; posPeople <= nPeople; ++posPeople) {
            fgets(buf, sizeof(buf), stdin);
            // sscanf(buf, "%[^,],%s", fst_name, snd_name);
            sscanf(buf, "%[A-Za-z], %s", fst_name, snd_name);
            mapNameToId[fst_name][snd_name] = posPeople;
            // printf("%s %s : %d\n", fst_name, snd_name, posPeople);
        }
        while (nRelation--) {
            int from = get_user_id(mapNameToId);
            int to = get_user_id(mapNameToId);
            edges[from].push_back(to);
            if (debug)
                printf("add %d -> %d\n", from, to);
        }

        for (int i = 1; i <= nPeople; ++i) {
            visited[i] = false;
            scc[i] = i;
            pos_in_stack[i] = NOT_IN_STACK;
        }
        std::stack<int> parents;

        for (int i = 1; i <= nPeople; ++i) {
            if (not visited[i])
                find_scc(i, parents);
        }

        int n_component = 0;
        for (int i = 1; i <= nPeople; ++i)
            if (scc[i] == i)
                ++n_component;

        printf("%d\n", n_component);
    }
    return 0;
}

