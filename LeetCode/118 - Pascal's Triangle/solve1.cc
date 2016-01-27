class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int> > vecPascal;
        for (int i = 0; i < numRows; ++i) {
            std::vector<int> vec;
            for (int k = 0; k <= i; ++k) {
                if (k == 0 or k == i)
                    vec.push_back(1);
                else
                    vec.push_back(vecPascal.back()[k-1]+vecPascal.back()[k]);
            }
            vecPascal.push_back(vec);
        }
        return vecPascal;
    }
};
