class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        std::string ans = "";
        for (const std::string & wd : d) {
            if (wd.size() < ans.size() || s.size() < wd.size()) continue;
            if (wd.size() == ans.size() && !(wd < ans)) continue;
            
            for (int i = 0, k = 0; i < s.size(); ++i) {
                if (s[i] == wd[k]) { ++k; }
                if (k == wd.size()) {
                    ans = wd;
                    break;
                }
            }
        }
        return ans;
    }
};
