#include <cstdio>
#include <cstring>
#include <string>

int ncity;
char lower_city[50], higher_city[50], src[50], dst[50];
int nchilds[26+5];
int parent[26+5];
int childs[26+5][26+5];
int level[26+5];

void compute_level_order(int cur_id, int cur_level) {
    level[cur_id] = cur_level;
    for (int i = 0; i < nchilds[cur_id]; ++i) {
        compute_level_order(childs[cur_id][i], cur_level+1);
    }
}

int find_common_ancestor(int src_id, int dst_id) {
    for (;src_id != dst_id;) {
        if (level[src_id] > level[dst_id]) src_id = parent[src_id];
        else if (level[src_id] < level[dst_id]) dst_id = parent[dst_id];
        else {
            src_id = parent[src_id]; dst_id = parent[dst_id];
        }
    }
    return src_id;
}

void get_road_to_ancestor(int cur, int ancestor, std::string & s) {
    while (cur != ancestor) {
        s += (cur + 'A');
        cur = parent[cur];
    }
}

// Represent as tree
// src -> common ancestor -> dst
int main() {
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int nRoad, nQuery;
        scanf("%d%d", &nRoad, &nQuery);
        const int RomeId = 'R'-'A';
        ncity = 1;
        memset(nchilds, 0, sizeof(nchilds));
        parent[RomeId] = RomeId;
        while (nRoad--) {
            scanf("%s%s", lower_city, higher_city);
            // printf("%c -> %c\n", lower_city[0], higher_city[0]);
            int lower_id = lower_city[0] - 'A';
            int higher_id = higher_city[0] - 'A';
            childs[lower_id][nchilds[lower_id]++] = higher_id;
            parent[higher_id] = lower_id;
        }
        compute_level_order(RomeId, 0);
        while (nQuery--) {
            scanf("%s%s", src, dst);
            int src_id = src[0] - 'A';
            int dst_id = dst[0] - 'A';
            int common_ancestor = find_common_ancestor(src_id, dst_id);
            std::string src_road, dst_road;
            get_road_to_ancestor(src_id, common_ancestor, src_road);
            get_road_to_ancestor(dst_id, common_ancestor, dst_road);
            for (int i = 0; i < src_road.size(); ++i)
                printf("%c", src_road[i]);
            printf("%c", common_ancestor+'A');
            for (int i = dst_road.size()-1; i >= 0; --i)
                printf("%c", dst_road[i]);
            printf("\n");
        }
        if (nCase != 0)
            printf("\n");
    }
    return 0;
}
