class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = (sz- (k % sz)) % sz;
        
        for (int i = 0; i < k; ++i)
            nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin()+k);
    }
};
