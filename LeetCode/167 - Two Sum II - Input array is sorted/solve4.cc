class Solution {
public:
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size()-1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            
            if (sum > target) --hi;
            else if (sum < target) ++lo;
            else {
                std::vector<int> ans = {lo+1, hi+1};
                return ans;
            }
        }
        return std::vector<int>();
    }
};

