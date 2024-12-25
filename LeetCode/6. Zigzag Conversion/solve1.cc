class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) 
            return s;
            
        string rows[numRows];
        for (int i = 0, r = 0, c = 0, dr = 1, dc = 0; i < s.size(); ++i) {
            rows[r].push_back(s[i]);
            if (r == numRows-1) dr = -1, dc = 1;
            else if (r == 0) dr = 1, dc = 0;
            r += dr, c += dc;
        }
        
        string res;
        for (int i = 0; i < numRows; ++i)
            res += rows[i];
        return res;
    }
};
