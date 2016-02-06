#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

const bool debug = false;

struct Object { 
    int _value, _weight;
    Object() {}
    Object(int value, int weight) : _value(value), _weight(weight) { }
    int value() const { return _value; }
    int weight() const { return _weight; }
};

const int MAX_NUM_OBJECT = 1000+5;
const int MAX_NUM_PEOPLE = 100+5;
Object object[MAX_NUM_OBJECT];
int A[MAX_NUM_OBJECT][30+5];
int W[MAX_NUM_PEOPLE];

void print_table(int nObject, const std::vector<int> & weights) {
    printf("        ");
    for (size_t i = 0; i < weights.size(); ++i)
        printf("%6d", weights[i]);
    printf("\n");
    for (int i = 0; i < nObject; ++i) {
        if (i == 0) printf("0(dummy)");
        else        printf("%8d", i);
        for (size_t k = 0; k < weights.size(); ++k)
            printf("%6d", A[i][k]);
        printf("\n");
    }
    printf("\n");
}

std::vector<int> getInterestedWeight(int nObject, int max_weight) {
    std::vector<bool> labels(max_weight+1, false);
    labels[0] = true;
    size_t nlabeled = 1;
    for (int i = 1; i < nObject; ++i) {
        int object_weight = object[i].weight();
        if (nlabeled > labels.size()/2) {
            for (int k = labels.size()-1; k > 0; --k)
                if (not labels[k] and k-object_weight >= 0 and labels[k-object_weight]) {
                    labels[k] = true;
                    ++nlabeled;
                }
        } else {
            for (int k = labels.size()-1; k >= 0; --k)
                if (labels[k] and k+object_weight < int(labels.size()) and not labels[k+object_weight]) {
                    labels[k+object_weight] = true;
                    ++nlabeled;
                }

        }
        if (nlabeled == labels.size())
            break;
    }

    std::vector<int> vecInterestedWeight;
    for (size_t i = 0; i < labels.size(); ++i)
        if (labels[i])
            vecInterestedWeight.push_back(i);

    if (debug) {
        printf("weight (max : %d): ", max_weight);
        for (size_t i = 0; i < vecInterestedWeight.size(); ++i)
            printf(" %d", vecInterestedWeight[i]);
        printf("\n");
    }

    return vecInterestedWeight;
}

int main() {
    int nCase, nObject, nPeople;
    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &nObject);
        ++nObject; // add dummy object
        for (int i = 1; i < nObject; ++i) 
            scanf("%d%d", &object[i]._value, &object[i]._weight);


        int total_value = 0;
        scanf("%d", &nPeople);
        int max_weight = 0;

        for (int i = 0; i < nPeople; ++i) {
            int cur_weight;
            scanf("%d", &cur_weight);
            W[i] = cur_weight;
            max_weight = std::max(max_weight, cur_weight);
        }
        std::vector<int> weights = getInterestedWeight(nObject, max_weight);
#if 1 

        for (int posPeople = 0; posPeople < nPeople; ++posPeople) {
            auto it = std::lower_bound(weights.begin(), weights.end(), W[posPeople]);
            if (it == weights.end()) it = weights.end()-1;
            else if (*it > W[posPeople]) --it;
            // assert(*it == W[posPeople]);
            int weight_size = it - weights.begin() + 1;
            if (debug)
                printf("*it = %d, weight size : %d\n", *it, weight_size);
            for (int i = 0; i < nObject; ++i) A[i][0] = 0;
            for (int i = 0; i < weight_size; ++i) A[0][i] = 0;

            for (int i = 1;i < nObject; ++i) {
                int object_weight = object[i].weight();
                int object_value = object[i].value();
                for (int k = 1; k < weight_size; ++k) {
                    int w = weights[k];
                    if (object_weight <= w) {
                        auto it = std::lower_bound(weights.begin(), weights.begin() + weight_size, w-object_weight);
                        assert(it != weights.end());
                        if (*it != (w-object_weight)) --it;
                        int prev_k = it - weights.begin();
                        A[i][k] = std::max(A[i-1][k], object_value + A[i-1][prev_k]);
                    } else {
                        A[i][k] = A[i-1][k];
                    }
                }
            }       

            if (debug) {
                print_table(nObject, weights);
                printf("  cur max : %d\n", A[nObject-1][weight_size-1]);
            }
            total_value += A[nObject-1][weight_size-1];
        }
#endif
        printf("%d\n", total_value);
    }
    return 0;
}
