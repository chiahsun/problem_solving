#include <cstdio>
#include <algorithm>

const int MAX_NUM_OBJECT = 30+5;
const int MAX_NUM_WEIGHT = 1000+5;
struct Object { int _weight, _value; };

Object objects[30+5];

int knapsack[MAX_NUM_OBJECT][MAX_NUM_WEIGHT];
bool taken[MAX_NUM_OBJECT][MAX_NUM_WEIGHT];
int ntaken[MAX_NUM_OBJECT][MAX_NUM_WEIGHT];

void print_taken_treasure(int curObject, int curWeight) {
    if (curObject > 0 and curWeight > 0) {
        if (taken[curObject][curWeight]) {
            print_taken_treasure(curObject-1, curWeight-objects[curObject]._weight);
            printf("%d %d\n", objects[curObject]._weight, objects[curObject]._value);
        } else {
            print_taken_treasure(curObject-1, curWeight);
        }
    }
}

int main() {
    bool firstCase = true;
    int T, W;
    int nObject;
    while (scanf("%d%d", &T, &W) == 2) {
        if (firstCase) firstCase = false;
        else printf("\n");

        int nWeight = T/3/W;

        scanf("%d", &nObject);
        for (int i = 1; i <= nObject; ++i)
            scanf("%d%d", &objects[i]._weight, &objects[i]._value);

        for (int i = 0; i <= nWeight; ++i) knapsack[0][i] = ntaken[0][i] = 0;
        for (int i = 0; i <= nObject; ++i) knapsack[i][0] = ntaken[i][0] = 0;

        for (int i = 1; i <= nObject; ++i)
            for (int k = 1; k <= nWeight; ++k) {
                int cur_object_weight = objects[i]._weight;
                int cur_object_value = objects[i]._value;
                taken[i][k] = false;
                ntaken[i][k] = ntaken[i-1][k];
                if (k < cur_object_weight) {
                    knapsack[i][k] = knapsack[i-1][k];
                } else {
                    int reduced_weight = k-cur_object_weight;
                    int taken_value = knapsack[i-1][reduced_weight] + cur_object_value;
                    if (taken_value > knapsack[i-1][k]) {
                        knapsack[i][k] = taken_value; 
                        taken[i][k] = true;
                        ntaken[i][k] = ntaken[i-1][reduced_weight] + 1;
                    } else {
                        knapsack[i][k] = knapsack[i-1][k]; 
                    }
                }
            }

        printf("%d\n", knapsack[nObject][nWeight]);
        printf("%d\n", ntaken[nObject][nWeight]);
        print_taken_treasure(nObject, nWeight);
    }
    return 0;
}
