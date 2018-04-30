class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> mapIntToFreq;
        
        int max = 1;
        for (int x : nums) {
            auto it = mapIntToFreq.find(x);
            if (it == mapIntToFreq.end()) mapIntToFreq.insert(std::make_pair(x, 1));
            else {
                ++it->second;
                max = std::max(max, it->second);
            }
        }
      
        std::vector<int> buckets[max+1];
        for (const auto & pr : mapIntToFreq) {
            buckets[pr.second].push_back(pr.first);
        }
        
        std::vector<int> ans;
        for (int i = max, used = 0; i > 0 && used < k; --i) {
            const std::vector<int> & current_bucket = buckets[i];
            for (int val : current_bucket) {
                ans.push_back(val);
                ++used;
                if (used >= k) break;
            }
        }
        
        return ans;
    }
};
