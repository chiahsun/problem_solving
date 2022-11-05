class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int N = numbers.size();
        for (int i = 0; i < N; ++i) {
            int a = numbers[i];
            int b = target-a;
            if (b < a) break;
            if (b > numbers.back()) continue;
            auto it = std::lower_bound(numbers.begin()+i+1, numbers.end(), b);
            if (it != numbers.end() && *it == b) {
                std::vector<int> ans;
                ans.push_back(i+1);
                ans.push_back(it-numbers.begin()+1);
                return ans;
            }
        }
        return std::vector<int>();
    }
};
