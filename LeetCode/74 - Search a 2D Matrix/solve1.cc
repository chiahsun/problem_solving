#include <iostream>
#include <vector>

using std::vector;
#include "solve1.h"


int main() {
    int M, N, T, x;
    std::cin >> M >> N >> T;
    std::cout << "M " << M << " N " << N << " T " << T << std::endl;

    std::vector<std::vector<int> > matrix;
    while (M--) {
        std::vector<int> v;
        for (int i = 0; i < N; ++i) {
            std::cin >> x;
            std::cout << "i = " << i << " val : " << x << " ";
            v.push_back(x);
        }
        std::cout << std::endl;
        matrix.push_back(v);
    }

    Solution s;
    std::cout << s.searchMatrix(matrix, T) << std::endl;

    return 0;
}
