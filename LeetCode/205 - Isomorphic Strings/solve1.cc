class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        char a[128];
        bool used[128];
        for (int i = 0; i < 128; ++i) {
            a[i] = '\0';
            used[i] = false;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (a[s[i]] == '\0') {
                if (used[t[i]]) return false;
                a[s[i]] = t[i];
                used[t[i]] = true;
            } else {
                if (a[s[i]] != t[i])
                    return false;
            }
        }
        
        return true;
    }
};
