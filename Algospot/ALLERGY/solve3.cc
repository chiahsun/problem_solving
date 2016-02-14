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
bool unique_dish[M];
int customer_cnt[M];

struct SizeCompare {
    bool operator () (const std::vector<int> & a, const std::vector<int> & b) const { return a.size() > b.size(); }
};


bool dish_used[M];
bool people_fulfilled[M];

void set_used(int dish_pos) {
    for (auto customer : dish_adjacent[dish_pos])
        people_fulfilled[customer] = true;
    dish_used[dish_pos] = true;
}

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
    if (unique_dish[dish_pos])
        dfs(dish_pos+1, n_fulfilled, n_dish, min_n_dish);
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
        // unique
        for (int i = 0; i < nDish; ++i) {
            std::sort(dish_adjacent[i].begin(), dish_adjacent[i].end());
            auto it = std::unique(dish_adjacent[i].begin(), dish_adjacent[i].end());
            dish_adjacent[i].resize(it-dish_adjacent[i].begin());
        }
        std::sort(dish_adjacent, dish_adjacent+nDish, SizeCompare());
        
        // get unique dish for unique customer
        memset(customer_cnt, 0, sizeof(customer_cnt));
        memset(unique_dish, false, sizeof(unique_dish));
        for (int i = 0; i < nDish; ++i) {
            for (auto customer : dish_adjacent[i])
                ++customer_cnt[customer];
        }
        int n_unique_dish = 0;
        for (int i = 0; i < nDish; ++i) {
            for (auto customer : dish_adjacent[i]) {
                if (customer_cnt[customer] == 1) {
                    unique_dish[i] = true;
                    ++n_unique_dish;
                    set_used(i);
                    break;
                }
            }
            
        }

        int n_fulfilled = 0;
        for (int i = 0; i < nPeople; ++i)
            if (people_fulfilled[i])
                ++n_fulfilled;

        int min_n_dish = nDish;
        dfs(0, n_fulfilled, n_unique_dish, min_n_dish);

        printf("%d\n", min_n_dish);
    }

    return 0;
}
