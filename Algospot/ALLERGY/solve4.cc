#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

const bool debug = false;

int nPeople, nDish;

std::map<std::string, int> mapPeopleId;
char buf[50];

const int M = 50+5;

const int CACHED_PRUNE_SIZE = 6;
std::set<unsigned long long> computed[M][M];
unsigned long long dish_mask[M];

struct SizeCompare {
    bool operator () (const std::vector<int> & a, const std::vector<int> & b) const { return a.size() > b.size(); }
};


bool dish_used[M];
unsigned long long people_fulfilled;

unsigned long long encode(int n_dish) {
    unsigned long long res = people_fulfilled;
    unsigned long long reverse_mask=0x1UL<<63;
    assert(reverse_mask != 0);
    while (n_dish > 0) {
        if (n_dish & 1)
            res |= reverse_mask;
        n_dish >>= 1;
        reverse_mask >>= 1;
    }
    return res;
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
#if 0 // cache won't make it faster 
    if (nDish - dish_pos < CACHED_PRUNE_SIZE) {
        unsigned long long code = encode(n_dish);
        if (computed[dish_pos][n_dish].count(code)) 
            return;
        else
            computed[dish_pos][n_dish].insert(code);
    }
#endif

    unsigned long long prev = people_fulfilled;
    unsigned long long after = dish_mask[dish_pos] | people_fulfilled;
    int n_cur_fullfill = 0;

    unsigned long long difference = prev ^ after;
    while (difference > 0) {
        difference &= (difference-1);
        ++n_cur_fullfill;
    }

    if (after != prev) {
        people_fulfilled = after;
        dish_used[dish_pos] = true;

        dfs(dish_pos+1, n_fulfilled+n_cur_fullfill, n_dish+1, min_n_dish);

        people_fulfilled = prev;
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
        memset(dish_mask, 0, sizeof(dish_mask));
        people_fulfilled = 0;

        for (int i = 0; i < nPeople; ++i) {
            scanf("%s", buf);
            mapPeopleId[buf] = i;
        }

        for (int i = 0; i < nDish; ++i) {

            int nCustomer;
            scanf("%d", &nCustomer);
            while (nCustomer--) {
                scanf("%s", buf);
                assert(mapPeopleId.count(buf));
                dish_mask[i] |= 1UL << (mapPeopleId[buf]);
            }
        }
       
        int min_n_dish = nDish;
        for (int i = 0; i < M; ++i)
            for (int k = 0; k < M; ++k)
                computed[i][k].clear();
        dfs(0, 0, 0, min_n_dish);

        printf("%d\n", min_n_dish);
    }

    return 0;
}
