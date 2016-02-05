#include <cstdio>
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
Object object[MAX_NUM_OBJECT];
int A[MAX_NUM_OBJECT][30+5];

void print_table(int nObject, int max_weight) {
    printf("        ");
    for (int i = 0; i < max_weight; ++i)
        printf("%6d", i);
    printf("\n");
    for (int i = 0; i < nObject; ++i) {
        if (i == 0) printf("0(dummy)");
        else        printf("%8d", i);
        for (int k = 0; k < max_weight; ++k)
            printf("%6d", A[i][k]);
        printf("\n");
    }
    printf("\n");
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
        while (nPeople--) {
            int max_weight;
            scanf("%d", &max_weight);
            ++max_weight; // because we have dummy 0 weight
            for (int i = 0; i < nObject; ++i) A[i][0] = 0;
            for (int i = 0; i < max_weight; ++i) A[0][i] = 0; // init dummy object
            if (debug)
                print_table(nObject, max_weight);
            for (int i = 1; i < nObject; ++i) {
                for (int k = 1; k < max_weight; ++k) {
                    int cur_weight = object[i].weight();
                    int cur_value = object[i].value();
                    if (cur_weight > k)
                        A[i][k] = A[i-1][k];
                    else
                        A[i][k] = std::max(A[i-1][k], cur_value + A[i-1][k-cur_weight]);
                }
                if (debug)
                    print_table(nObject, max_weight);
            }
            total_value += A[nObject-1][max_weight-1];
        }
        printf("%d\n", total_value);
    }
    return 0;
}
