class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' or c == '[' or c == '{') st.push(c);
            else {
                char reverse_c = '(';
                if (c == ']') reverse_c = '[';
                else if (c == '}') reverse_c = '{';
                
                if (st.empty() or st.top() != reverse_c) return false;
                st.pop();
            }
            if (st.size() > (s.size() - i - 1))
                return false;
        }
        
        return st.empty();
    }
};
