struct Candidate {
    std::string s_;
    int count_;
    Candidate(const std::string & s, int count) : s_(s), count_(count) { }
    bool operator < (const Candidate & other) const {
        if (count_ != other.count_) return count_ > other.count_;
        return s_ < other.s_;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> m;
        for (const std::string & s :words) {
            auto it = m.find(s);
            if (it == m.end()) m.insert(std::make_pair(s, 1));
            else ++it->second;
        }
        
        std::vector<Candidate> v;
        for (const auto & pr : m) {
            v.push_back(Candidate(pr.first, pr.second));
        }
        
        std::vector<std::string> ans;
        std::sort(v.begin(), v.end());
        for (int i = 0; i < k && i < v.size(); ++i) {
            ans.push_back(v[i].s_);
        }
        
        return ans;
    }
};
