class Solution {
public:
    int firstUniqChar(string s) {
        const int NOT_FOUND = -1, DUPLICATE = -2;
        const int N = 26;
        int first_index[N];
        for (int i = 0; i < N; ++i) first_index[i] = NOT_FOUND;
        
        for (int i = 0; i < s.size(); ++i) {
            int cur = s[i] - 'a';
            if (first_index[cur] == DUPLICATE) { }
            else if (first_index[cur] == NOT_FOUND) { 
                first_index[cur] = i;
            } else {
                first_index[cur] = DUPLICATE;
            }
        }
        int min_index = -1;
        for (int i = 0; i < N; ++i) {
            int cur = first_index[i];
            if (cur >= 0) {
                if (min_index == -1 || cur < min_index) min_index = cur;
            }
        }
        return min_index;
    }
};
