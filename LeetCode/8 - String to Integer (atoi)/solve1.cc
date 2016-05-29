class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        
        int i = 0;
        while (i < str.size() and isspace(str[i])) ++i;
        
        if (i >= str.size()) return 0;
        bool neg = false;
        
        if (str[i] == '-')        neg = true, ++i;
        else if (str[i] == '+')   ++i;
        
        if (i >= str.size()) return 0;
        
        int val = 0;
        while (i < str.size() and isdigit(str[i])) {
            if (val > INT_MAX/10) return INT_MAX;
            if (val < INT_MIN/10) return INT_MIN;
            val *= 10;
            
            int now = str[i] - '0';
            if (val > INT_MAX - now) return INT_MAX;
            if (val < INT_MIN + now) return INT_MIN;
            if (neg)     val -= now;
            else         val += now;
            ++i;
        }
        
        return val;
    }
};
