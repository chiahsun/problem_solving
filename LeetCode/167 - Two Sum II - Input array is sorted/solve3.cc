class Solution {
public:
    int binary_search(std::vector<int> & v, int lo, int target) {
        int hi = v.size()-1, mid;
        while (lo <= hi) {
            mid = lo + (hi-lo)/2;
            if (v[mid] > target) hi = mid-1;
            else if (v[mid] < target) lo = mid+1;
            else return mid;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int N = numbers.size();
        for (int i = 0; i < N; ++i) {
            int a = numbers[i];
            int b = target-a;
            if (b < a) break;
            if (b > numbers.back()) continue;
            int index = binary_search(numbers, i+1, b);
            if (index != -1) {
                std::vector<int> ans;
                ans.push_back(i+1);
                ans.push_back(index+1);
                return ans;
            }
        }
        return std::vector<int>();
    }
};

