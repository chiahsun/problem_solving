struct CharToFreq {
    char c_;
    int freq_;
    CharToFreq(char c, int freq) : c_(c), freq_(freq) { }
    bool operator < (const CharToFreq & other) const {
        if (freq_ != other.freq_) return freq_ > other.freq_;
        return c_ < other.c_;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        std::map<char, int> mapCharToFreq;
        for (char c : s) {
            auto it = mapCharToFreq.find(c);
            if (it != mapCharToFreq.end()) ++it->second;
            else mapCharToFreq.insert(std::make_pair(c, 1));
        }
        
        std::vector<CharToFreq> v;
        for (const auto & pr : mapCharToFreq) {
            v.push_back(CharToFreq(pr.first, pr.second));
        }
        std::sort(v.begin(), v.end());
        
        std::string ans;
        for (auto x : v) {
            for (int i = 0; i < x.freq_; ++i) {
                ans += x.c_;
            }
        }
        
        return ans;
    }
};
