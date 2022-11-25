class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())       return "";
        if (strs.size() == 1)   return strs.front();
        

        int max_len = -1;
        for (int i = 0; max_len < 0; ++i) {
            for (int pos_str = 0; pos_str < strs.size(); ++pos_str) {
                if ( (i >= strs[pos_str].size())
                  or (pos_str != 0 and (strs[pos_str][i] != strs[pos_str-1][i])) ) {
                      max_len = i;
                      break;
                  }
                    
            }
        }
        
        return strs.front().substr(0, max_len);
    }
};
