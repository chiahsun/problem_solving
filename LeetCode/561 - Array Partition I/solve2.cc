class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::map<int, int> m;
        for (int val : nums) {
            if (!m.count(val)) m[val] = 1;
            else ++m[val];
        }
        int sum = 0;
        bool usePrevElement = false;
        for (auto & pr : m) {
            if (usePrevElement) --pr.second;
            
            usePrevElement = (pr.second % 2 != 0);
            int cur_count = pr.second/2 + (usePrevElement ? 1 : 0);
            sum += pr.first * cur_count;
        }
        
        return sum;
    }
};
