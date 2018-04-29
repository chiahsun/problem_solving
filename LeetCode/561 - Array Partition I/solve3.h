class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int min, max;
        min = max = nums[0];
        for (int val : nums) {
            min = std::min(min, val);
            max = std::max(max, val);
        }
        const int N = max-min+1;
        int count[N];
        memset(count, 0, sizeof(int)*N);
        for (int val : nums) {
            ++count[val - min];
        }
        
        int sum = 0;
        int used = 0;
        for (int i = 0; i < N; ++i) {
            if (count[i] > 0) {
                count[i] -= used;
                used = 0;
            
                if (count[i] > 0) {
                    used = count[i] % 2;
                    int cur_count = count[i]/2 + used;
                    sum += (min + i) * cur_count;
                }
            }
        }
        
        return sum;
    }
};
