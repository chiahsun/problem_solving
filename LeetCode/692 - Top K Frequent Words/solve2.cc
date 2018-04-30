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
        
        std::priority_queue<Candidate> pq;
        for (const auto & pr : m) {
            pq.push(Candidate(pr.first, pr.second));
            if (pq.size() > k) pq.pop();
        }
        
        std::vector<std::string> ans;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            Candidate x = pq.top(); pq.pop();
            ans.push_back(x.s_);
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
