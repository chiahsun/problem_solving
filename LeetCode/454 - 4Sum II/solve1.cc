class Solution {
public:
    void count(vector<int>& A, vector<int>& B, std::map<int, int>& m) {
        for (int i = 0; i < A.size(); ++i) {
            for (int k = 0; k < B.size(); ++k) {
                int sum = A[i] + B[k];
                auto it = m.find(sum);
                if (it == m.end()) { m.insert(std::make_pair(sum, 1)); }
                else { ++it->second; }
            }
        }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        std::map<int, int> m1, m2;
        
        count(A, B, m1);
        count(C, D, m2);
        
        int count = 0;
        for (const auto & pr: m1) {
            auto it = m2.lower_bound(-pr.first);
            if (it != m2.end() && it->first == -pr.first) {
                count += (pr.second * it->second);
            }
        }
        
        return count;
    }
};
