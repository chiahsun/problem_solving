class Solution {
public:
    int lengthOfLastWord(string s) {
        int begin = 0, end;
        int len = 0;
        while (begin < s.size()) {
            while (begin < s.size() and s[begin] == ' ') ++begin;
            if (begin >= s.size()) break;
            end = begin+1;
            while (end < s.size() and s[end] != ' ') ++end;
            len = end - begin;
            begin = end+1;
        }
        return len;
    }
};
