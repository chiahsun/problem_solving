class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> ans;
        for (int i = left; i <= right; ++i) {
            bool ok = true;
            int left = i;
            while (left > 0) {
                int digit = left % 10;
                if (digit == 0 || i % digit != 0) { ok = false; break; }
                left /= 10;
            }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};
