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
        std::unordered_map<int, int> mapIntToFreq;
        
        for (int x : nums) {
            auto it = mapIntToFreq.find(x);
            if (it == mapIntToFreq.end()) mapIntToFreq.insert(std::make_pair(x, 1));
            else ++it->second;
        }
        
        std::vector<IntToFreq> v;
        for (const auto & x : mapIntToFreq) v.push_back(IntToFreq(x.first, x.second));
        
        std::sort(v.begin(), v.end());
        
        std::vector<int> ans;
        for (int i = 0; i < k && i < v.size(); ++i) {
            ans.push_back(v[i].number_);
        }
        
        return ans;
    }
};

