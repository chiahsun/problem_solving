class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> prev, cur;
        cur.push_back(1);
        if (rowIndex == 0) return cur;
        for (int i = 0; i < rowIndex; ++i) {
            prev = cur;
            cur.clear();
            cur.push_back(1);
            for (int k = 1; k <= i; ++k)
                cur.push_back(prev[k-1]+prev[k]);
            cur.push_back(1);
        }
        return cur;
    }
};
