#include <ctime>
#include <iostream>
#include <vector>

void shuffle(std::vector<int> & nums) {
    for (int i = nums.size(); i > 1; --i) {
        int pos = rand() % i;
        std::swap(nums[pos], nums[i-1]);
    }
}


int main() {
    const int N = 5;
    std::vector<int> v;
    for (int i = 0; i < N; ++i) {
        v.push_back(i);
    }

    int cnt[N][N] = {0};
    for (int i = 0; i < 1000000; ++i) {
        shuffle(v);
        for (int k = 0; k < v.size(); ++k) {
            ++cnt[k][v[k]];
        }
        /*for (int k = 0; k < v.size(); ++k) {
            std::cout << v[k] << " ";
        }
        std::cout << std::endl;*/
    }

    for (int i = 0; i < N; ++i) {
        std::cout << "Pos " << i << std::endl;
        for (int k = 0; k < N; ++k) {
            std::cout << "(val " << k << " cnt: " << cnt[i][k] << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
