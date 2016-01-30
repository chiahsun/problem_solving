class Solution {
public:
    int minPatches(vector<int> & num, int n) {
        int npatch = 0, lower = 0, pos_num = 0;
        while (lower < n) {
            int next = lower+1;
            if (pos_num < num.size() and num[pos_num] <= lower+1) {
                next = num[pos_num++];
            } else {
                ++npatch;
            }
            if (n-next <= lower)
                break;
            lower = lower+next;
        }
        // printf("npatch : %d\n", npatch);
        return npatch;
    }
};
