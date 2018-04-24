class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> ans(nums.size(), -1);
        
        std::stack<int> st;
        for (int i = 0; i < nums.size()*2; ++i) {
            int cur_pos = (i >= nums.size()) ? i - nums.size() : i;
            int cur = nums[cur_pos];
            while (!st.empty()) {
                int top_pos = st.top(); 
                if (nums[top_pos] < cur) {
                    ans[top_pos] = cur;
                    st.pop();
                } else {
                    break;
                }
            }
            if (i < nums.size())
                st.push(i);
        }
        
        return ans;
    }
};
