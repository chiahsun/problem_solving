class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        std::vector<int> v(S.size(), S.size());
        for (int i = 0; i < S.size(); ++i) {
            char cur = S[i];
            if (cur == C) {
                v[i] = 0;
                int pos = i+1, cnt = 1;
                while (pos < S.size() && cnt < v[pos]) { v[pos] = cnt; ++pos; ++cnt; }
                pos = i-1, cnt = 1;
                while (pos >= 0 && cnt < v[pos]) { v[pos] = cnt; --pos; ++cnt; }
            }
        }
        
        return v;
    }
};
