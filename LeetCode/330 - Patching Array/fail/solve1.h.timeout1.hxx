class Solution {
public:
    const bool debug = false;
    void add_number(int x, std::vector<bool> & sum, int n) {
        if (debug)
            printf("add %d : ", x);
        for (int i = sum.size()-1; i >= 0; --i) {
            if (sum[i]) {
                int next = i+x;
                if (next <= n) {
                    if (next >= sum.size())
                        sum.resize(next+1);
                    sum[next] = true;
                }
            }
        }
        if (debug) {
            for (int i = 0; i < sum.size(); ++i)
                if (sum[i])
                    printf(" %d", i);
            printf("\n");
        }
    }
    int compute_lower(int prev_lower, std::vector<bool> & sum) {
        for (int i = prev_lower; i < sum.size(); ++i)
            if (not sum[i])
                return i-1;
        return sum.size()-1;
    }
    int minPatches(vector<int>& nums, int n) {
        std::vector<bool> sum = {true};
        int lower = 0;
        for (auto x : nums) {
            add_number(x, sum, n);
            lower = compute_lower(0, sum);
            if (lower >= n)
                return 0;
        }
         
        int npatch = 0;
        while (lower + 1 != sum.size()) {
            add_number(lower+1, sum, n);
            ++npatch;
            lower = compute_lower(lower, sum);
        }
        while (lower < n) {
            ++npatch;
            if (n - lower <= (lower+1)) 
                break;
            
            lower += (lower+1);
            if (debug)
                printf("cur lower :  %d\n", lower);
        }
        if (debug)
            printf("npatch : %d\n", npatch);
        return npatch;
    }
};
