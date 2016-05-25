class Solution {
public:
    char get_reverse(char c) {
        char a[2][3] = { {'(', '[', '{'}
                       , {')', ']', '}'} };
        for (int i = 0; i < 3; ++i)
            if (a[1][i] == c)
                return a[0][i];
        return '0';
    }
    bool isValid(string s) {
        std::stack<char> st;
        for (const char & c : s) {
            if (c == '(' or c == '[' or c == '{') st.push(c);
            else if (c == ')' or c == ']' or c == '}') {
                if (st.empty() or (st.top() != get_reverse(c))) return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};
