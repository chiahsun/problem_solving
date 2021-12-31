class Solution {
public:

    int countPrimes(int n) {
        static std::vector<int> table = {0, 0, 1, 2, 2, 3};;
        if (n <= 0)             return 0;
        if (n < table.size())   return table[n-1];
        
        table.reserve(n);

        int n_prime = table.back();
        
        for (int i = table.size(); i < n; ++i) {
            if (i % 2 == 0 or i % 3 == 0 or i % 5 == 0) {
                table.push_back(n_prime);
            } else {
                bool good = true;
                for (int k = 7; k*k <= i; k += 6) {
                    if (i % k == 0 or i % (k+4) == 0) {
                        good = false;
                        break;
                    }
                }
                if (good) ++n_prime;
                table.push_back(n_prime);
            }
        }
        
        return table.back();
    }
};
