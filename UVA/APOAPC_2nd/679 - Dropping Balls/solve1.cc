#include <cstdio>

// const bool debug = true;
const bool debug = false;

const int M = 20+3;
int powers[M];


void get_direction_helper(const int & x, const int & depth, int & head, int & cur_depth, int & val) {
    if (cur_depth == depth)
        return;
    int difference = x - head;
    cur_depth += 1;
    if (difference % powers[cur_depth-1] == 0) { // go left
        if (debug)
        printf("0 (%d), ", val);
        get_direction_helper(x, depth, head, cur_depth, val);
    } else { // go right
        val += powers[depth-cur_depth];
        if (debug)
        printf("1 (%d), ", val);
        head += powers[cur_depth-2];
        get_direction_helper(x, depth, head, cur_depth, val);
    }
}

int get_direction(int x, int depth) {
    int cur_depth = 1;
    int head = 1;
    int val = powers[depth-1];
    get_direction_helper(x, depth, head, cur_depth, val);
//    printf("\n");
    return val;
}

int main() {
    powers[0] = 1;
    for (int i = 1; i < M; ++i) powers[i] = powers[i-1] * 2;
//    for (int i = 0; i < M; ++i) printf("%d ", powers[i]);
    int nCase;
    while (scanf("%d", &nCase) == 1 and nCase != -1) {
        while (nCase--) {
            int x, depth;
            scanf("%d%d", &depth, &x);
            printf("%d\n", get_direction(x, depth));
        }
    }

    return 0;
}
