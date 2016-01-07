class Solution {
public:
    int getCharValue(char c) {
        switch(c) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default: break;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            int val1 = getCharValue(s[i]);
            if ((i + 1) == s.size()) {
                sum += val1;
                break;
            }
            int val2 = getCharValue(s[i+1]);
            if (val2 > val1) {
                sum += (val2 - val1);
                ++i;
            } else {
                sum += val1;
            }
        }
        return sum;
    }
};
