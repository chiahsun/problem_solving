class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) 
            return 0;
        
        bool table[n];
        std::fill(table, table+n, true);
        
        table[0] = table[1] = false;
        for (int i = 4; i < n; i += 2) 
            table[i] = false;
            
        for (int i = 3; i < n; i += 2) {
            if (table[i]) {
                for (int k = i+i+i; k < n; k += 2*i)
                    table[k] = false;
            }
        }
        
        int n_prime = 1;
        for (int i = 3; i < n; i += 2)
            if (table[i])
                ++n_prime;
        
        return n_prime;
    }
};
