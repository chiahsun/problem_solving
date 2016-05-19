#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;

const bool debug = false;

class Solution {
public:
    static bool init_table(int* table) {
        table[0] = table[1] = 1;
        for (int i = 2; i <= 12; ++i) {
            table[i] = table[i-1] * i;
        }
        return true;
    }
    static int get_factorial(int n) {
        static int table[15];
        static bool init = init_table(table); (void)(init); // supress warning
        return table[n];
    }

    std::string get_string(const std::vector<int> & v) {
        std::string s;
        for (int i = 0; i < v.size(); ++i)
            s += std::to_string(v[i]);
        return s;
    }

    string getPermutation(int n, int k) {
        k -= 1;
        std::vector<int> v;
        for (int i = 1; i <= n; ++i) v.push_back(i);
        for (int i = 0; i < n; ++i) {
            if (debug)
                std::cout << "now : " << get_string(v) << " with i : " << i << " with k : " << k << std::endl;
            int d = n - i - 1;
            int p2 = k/get_factorial(d);
            if (p2 > 0) {
                if (debug)
                    std::cout << "p2 : " << p2 << " v[i] = " << v[i] << std::endl;
                int tmp = v[i+p2];
                for (int m = i+p2; m > i; --m)
                    v[m] = v[m-1];
                v[i] = tmp;
//                std::swap(v[i+p2], v[i]);
                k -= p2 * get_factorial(d);
            }
            if (k == 0)
                break;
        }

        return get_string(v);
    }

};
    
int main() {
    for (int i = 1; i<= 4; ++i)
        std::cout << "factor(" << i << ") = " << Solution::get_factorial(i) << std::endl;
    std::cout << Solution().getPermutation(1, 1) << std::endl;
    std::cout << Solution().getPermutation(2, 1) << std::endl;
    std::cout << Solution().getPermutation(2, 2) << std::endl;
    std::cout << Solution().getPermutation(3, 1) << std::endl;
    std::cout << Solution().getPermutation(3, 2) << std::endl;
    std::cout << Solution().getPermutation(3, 3) << std::endl;
    std::cout << Solution().getPermutation(3, 4) << std::endl;
    std::cout << Solution().getPermutation(3, 5) << std::endl;
    std::cout << Solution().getPermutation(3, 6) << std::endl;
    return 0;
}
