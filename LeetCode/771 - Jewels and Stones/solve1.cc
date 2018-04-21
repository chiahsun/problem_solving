class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            for (int k = 0; k < J.size(); ++k) {
                if (S[i] == J[k]) {
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};
