#include <algorithm>
#include <iostream>
#include <vector>

void get_nth_permutation(int num, int nth) {
    std::vector<int> vec;
    for (int i = 0; i < num; ++i)
        vec.push_back(i);
    do {
    } while(nth-- && std::next_permutation(vec.begin(), vec.end()));

    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main() {
    get_nth_permutation(3, 0);
    get_nth_permutation(3, 1);
    get_nth_permutation(3, 2);
    get_nth_permutation(3, 3);
    get_nth_permutation(10, 1000000-1);
    return 0;
}
