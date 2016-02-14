#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

const bool debug = false;

int nPeople, nDish;

std::map<std::string, int> mapPeopleId;
char buf[50];

const int M = 50+5;

std::vector<int> dish_adjacent[M];

struct SizeCompare {
    bool operator () (const std::vector<int> & a, const std::vector<int> & b) const { return a.size() > b.size(); }
};


bool dish_used[M];
bool people_fulfilled[M];

void dfs(int dish_pos, int n_fulfilled, int n_dish, int & min_n_dish) {
    if (n_fulfilled >= nPeople) {
        if (debug and n_dish < min_n_dish) {
            for (int i = 0; i < nDish; ++i)
                if (dish_used[i])
                    printf("%d ", i);
            printf("\n");
        }
        min_n_dish = std::min(min_n_dish, n_dish);
        return;
    }
    if (dish_pos >= nDish)
        return;
    if (n_dish >= min_n_dish)
        return;
    std::vector<int> cur_fullfilled;
    for (auto customer : dish_adjacent[dish_pos]) {
        if (not people_fulfilled[customer]) {
            cur_fullfilled.push_back(customer);
        }
    }
    if (cur_fullfilled.size() != 0) {
        for (auto customer : cur_fullfilled)
            people_fulfilled[customer] = true;
        dish_used[dish_pos] = true;

        dfs(dish_pos+1, n_fulfilled+cur_fullfilled.size(), n_dish+1, min_n_dish);

        for (auto customer : cur_fullfilled)
            people_fulfilled[customer] = false;
        dish_used[dish_pos] = false;
    }

    dfs(dish_pos+1, n_fulfilled, n_dish, min_n_dish);
}

int main() {

    int nCase;
    scanf("%d", &nCase);

    while (nCase--) {
        mapPeopleId.clear();

        scanf("%d%d", &nPeople, &nDish);
        memset(dish_used, false, sizeof(dish_used));
        memset(people_fulfilled, false, sizeof(people_fulfilled));

        for (int i = 0; i < nPeople; ++i) {
            scanf("%s", buf);
            mapPeopleId[buf] = i;
        }

        for (int i = 0; i < nDish; ++i) {
            dish_adjacent[i].clear();

            int nCustomer;
            scanf("%d", &nCustomer);
            while (nCustomer--) {
                scanf("%s", buf);
                assert(mapPeopleId.count(buf));
                dish_adjacent[i].push_back(mapPeopleId[buf]);
            }
        }
#if 0 
        // unique
        for (int i = 0; i < nDish; ++i) {
            printf("unique :");
            for (auto x : dish_adjacent[i]) printf(" %d", x);
            printf(" ->");
            std::sort(dish_adjacent[i].begin(), dish_adjacent[i].end());
            auto it = std::unique(dish_adjacent[i].begin(), dish_adjacent[i].end());
            dish_adjacent[i].resize(it-dish_adjacent[i].begin());
            for (auto x : dish_adjacent[i]) printf(" %d", x);
            printf("\n");
        }
#endif
//        std::sort(dish_adjacent, dish_adjacent+nDish, SizeCompare());
       
        int min_n_dish = nDish;
        dfs(0, 0, 0, min_n_dish);

        printf("%d\n", min_n_dish);
    }

    return 0;
}
