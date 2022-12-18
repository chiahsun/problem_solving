struct IntToFreq {
    int number_;
    int freq_;
    IntToFreq(int number, int freq) : number_(number), freq_(freq) { }
    
    bool operator < (const IntToFreq & other) const {
        if (freq_ != other.freq_) return freq_ > other.freq_;
        return number_ < other.number_;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> mapIntToFreq;
        
        for (int x : nums) {
            auto it = mapIntToFreq.find(x);
            if (it == mapIntToFreq.end()) mapIntToFreq.insert(std::make_pair(x, 1));
            else ++it->second;
        }
        
        std::priority_queue<IntToFreq> pq;
        for (const auto & pr : mapIntToFreq) {
            pq.push(IntToFreq(pr.first, pr.second));
            if (pq.size() > k) pq.pop();
        }
        
        std::vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().number_);
            pq.pop();
        }
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
