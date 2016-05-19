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
            int d = n - i - 1;
            int p2 = k/get_factorial(d);
            if (p2 > 0) {
                int tmp = v[i+p2];
                for (int m = i+p2; m > i; --m)
                    v[m] = v[m-1];
                v[i] = tmp;
                k -= p2 * get_factorial(d);
            }
            if (k == 0)
                break;
        }

        return get_string(v);
    }

};
