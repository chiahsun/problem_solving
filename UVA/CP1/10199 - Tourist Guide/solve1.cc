#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const bool debug = false;

char buf[50];

int nCity;
std::vector<std::string> vecCity;
std::map<std::string, int> mapCityAndId;
std::vector<std::vector<int> > edges;
bool visited[100+5];
const int NOT_IN_STACK = -1;
int depth[100+5];

int get_city_id() {
    bool ok = (scanf("%s", buf) == 1); assert(ok);
    assert (mapCityAndId.count(buf)); 
    return mapCityAndId[buf];
}

int dfs(int cur, int cur_depth, std::vector<std::string> & vecCamera) {
    if (debug)
        printf("%d (depth:%d)\n", cur, cur_depth);
    visited[cur] = true;
    depth[cur] = cur_depth;

    int n_child_tree = 0;
    int n_child_tree_no_back_edge = 0;
    int lowerest_ancestor_depth = cur_depth;
    for (int next : edges[cur]) {
        if (visited[next]) {
            if (depth[next] < lowerest_ancestor_depth) {
                if (debug)
                    printf("  set lowerest ancestor depth to %d for %d (depth : %d)\n", depth[next], cur, depth[cur]);
                lowerest_ancestor_depth = depth[next];
            }
        } else {
            ++n_child_tree;
            int next_lowerest_ancestor_depth = dfs(next, cur_depth+1, vecCamera);

            if (next_lowerest_ancestor_depth >= cur_depth)
                ++n_child_tree_no_back_edge;
            if (next_lowerest_ancestor_depth < lowerest_ancestor_depth) {
                if (debug)
                    printf("  set lowerest ancestor depth to %d for %d (depth : %d)\n", depth[next], cur, depth[cur]);
                lowerest_ancestor_depth = next_lowerest_ancestor_depth;
            }
        }
    }
    if (cur_depth == 0) {
        if (n_child_tree > 1) {
            vecCamera.push_back(vecCity[cur]);
            if (debug)
                printf("%d is cut vertex\n", cur);
        }
    } else if (n_child_tree_no_back_edge > 0) {
        vecCamera.push_back(vecCity[cur]);
        if (debug)
            printf("%d is cut vertex\n", cur);
    }

    return lowerest_ancestor_depth;
}

void find_cut_vertex(std::vector<std::string> & vecCamera) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < nCity; ++i)
        if (not visited[i])
            dfs(i, 0, vecCamera);
}

int main() {
    int nEdge, posCase = 1;
    while (scanf("%d", &nCity) == 1 and nCity) {
        vecCity.clear();
        mapCityAndId.clear();
        edges.clear();
        edges.resize(nCity);
        for (int i = 0; i < nCity; ++i) { 
            bool ok = (scanf("%s", buf) == 1); assert(ok);
            vecCity.push_back(buf);
            mapCityAndId.insert(std::make_pair(buf, mapCityAndId.size()));
            if (debug)
                printf("add city : %s -> %d\n", buf, mapCityAndId[buf]);
        }
        scanf("%d", &nEdge);
        while (nEdge--) {
            int one_city = get_city_id();
            int another_city = get_city_id();
            assert(one_city < edges.size());
            assert(another_city < edges.size());
            if (debug)
                printf("add edge : %d <-> %d\n", one_city, another_city);
            edges[one_city].push_back(another_city);
            edges[another_city].push_back(one_city);
        }

        // unique
        for (int i = 0; i < nCity; ++i) {
            std::sort(edges[i].begin(), edges[i].end());
            auto it = std::unique(edges[i].begin(), edges[i].end());
            edges[i].resize(it-edges[i].begin());
        }

        std::vector<std::string> vecCamera;
        find_cut_vertex(vecCamera);
        
        std::sort(vecCamera.begin(), vecCamera.end());

        if (posCase != 1) printf("\n");
        printf("City map #%d: %lu camera(s) found\n", posCase++, vecCamera.size());
        for (int i = 0; i < vecCamera.size(); ++i) 
            printf("%s\n", vecCamera[i].c_str());
        
    }
    return 0;
}

