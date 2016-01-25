#include <cstdio>
#include <algorithm>

int main() {
    int nPeople, budget, nHotel, nWeek, price, space;

    while (scanf("%d%d%d%d", &nPeople, &budget, &nHotel, &nWeek) == 4) {
        int min_budget = budget+1;
        while (nHotel--) {
            scanf("%d", &price);
            bool found = false;
            for (int posWeek = 0; posWeek < nWeek; ++posWeek) {
                scanf("%d", &space);
                if (not found and (space >= nPeople)) {
                    min_budget = std::min(min_budget, nPeople * price);
                    found = true;
                }
            }
        }

        if (min_budget <= budget)
            printf("%d\n", min_budget);
        else
            printf("stay home\n");
    }
    return 0;
}
