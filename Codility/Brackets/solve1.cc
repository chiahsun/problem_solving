#include <stack>
#include <unordered_map>

static std::unordered_map<char, char> m = {{']', '['}, {'}','{'}, {')','('}};

int solution(string &S) {
    std::stack<char> st;
    for (char c : S) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ']':
            case '}':
            case ')':
                if (st.empty() || st.top() != m[c]) {
                    return 0;
                }
                st.pop();
                break;
            default:
                break;
        }
    }
    
    return st.empty();
}
