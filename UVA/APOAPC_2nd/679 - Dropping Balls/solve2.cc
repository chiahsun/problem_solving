#include <cstdio>

// const bool debug = true;
const bool debug = false;

const int M = 20+3;
int powers[M];


int get_direction(const int & x, const int & depth) {
    int val = powers[depth-1];
    for (int cur_depth = 1, head = 1; cur_depth != depth; ++cur_depth) {
        if (((x - head) % powers[cur_depth]) != 0) {
            val += powers[depth-cur_depth-1];
            head += powers[cur_depth-1];
        }
    }
    return val;
}


int main() {
    powers[0] = 1;
    for (int i = 1; i < M; ++i) powers[i] = powers[i-1] * 2;
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
