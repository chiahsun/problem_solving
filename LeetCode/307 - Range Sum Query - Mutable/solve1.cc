#include <iostream>
#include <vector>

using std::vector;
#include "solve1.h"

int main() {
    int N, x;
    std::vector<int> v;
    std::cin >> N;
    while (N--) {
        std::cin >> x;
        v.push_back(x);
    }

    char C;
    int i, k;
    NumArray s(v);
    while (std::cin >> C >> i >> k) {
        if (C == 'S') {
            std::cout << "sumRange " << i << " " << k << " : " << s.sumRange(i, k) << std::endl;
        } else if (C == 'U') {
            std::cout << "update " << i << " with val " << k << std::endl;
            s.update(i, k);
        }
    }

    return 0;
}
