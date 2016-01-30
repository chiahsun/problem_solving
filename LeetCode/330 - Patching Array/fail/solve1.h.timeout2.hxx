class Solution {
public:
    const bool debug = !false;
    void add_number(int x, std::vector<bool> & sum, int lower, int n, int & tick) {
        if (debug)
            printf("add %d with lower %d : ", x, lower);
        if (x > n)
            return;
        for (int i = sum.size()-1; i >= 0; --i) {
            if (debug) {
                printf(" c");
            }
            ++tick;
            if (sum[i]) {
                int next = i+x;
                if (next <= n) {
                    if (next >= sum.size())
                        sum.resize(next+1);
                    sum[next] = true;
                }
                if (next < lower)
                    break;
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
        int lower = 0;
        int pos = 0;
        for (;pos<nums.size(); ++pos) {
            int x = nums[pos];
            if (x <= lower+1)
                lower += x;
            else
                break;
            if (lower >= n)
                return 0;
        }

        int tick = 0;
        std::vector<bool> sum(lower+1, true);
        for (;pos<nums.size(); ++pos) {
            int x = nums[pos];
            add_number(x, sum, lower, n, tick);
            lower = compute_lower(0, sum);
            if (lower >= n) {
                printf("npatch : 0 with tick(%d)\n", tick);
                return 0;
            }
        }
         
        int npatch = 0;
        while (lower + 1 != sum.size()) {
            add_number(lower+1, sum, lower, n, tick);
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
            printf("npatch : %d with tick(%d)\n", npatch, tick);
        return npatch;
    }
};
