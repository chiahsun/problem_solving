class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int nlines = 0, count = 0;
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            int curCount = widths[c - 'a'];
            if (count + curCount > 100) {
                ++nlines;
                count = curCount;
            } else {
                count += curCount;
            }
        }
        if (count != 0) ++nlines;    
        std::vector<int> ans = {nlines, count};
        return ans;
    }
};
