class Solution {
public:
    void trim(std::string & s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') {
                s = s.substr(i+1, s.size());
                return;
            }
        }
        s = "";
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        std::unordered_map<std::string, int> m;
        
        for (const auto & cpdomain : cpdomains) {
            int count;
            char domain[256];
            sscanf(cpdomain.c_str(), "%d %s", &count, domain);
            
            std::string s = domain;
            do {
                m[s] += count;
                trim(s);
            } while (!s.empty());
        }
        
        std::vector<std::string> ans;
        for (const auto & pr : m) {
            ans.push_back(std::to_string(pr.second) + " " + pr.first);
        }
        return ans;
    }
};
