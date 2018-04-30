class Solution {
public:
    void count(vector<int>& A, vector<int>& B, std::unordered_map<int, int>& m) {
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
        std::unordered_map<int, int> m1;
        
        count(A, B, m1);
        
        int count = 0;
        for (int i = 0; i < C.size(); ++i) {
            for (int k = 0; k < D.size(); ++k) {
                int sum = C[i] + D[k];
                auto it = m1.find(-sum);
                if (it != m1.end()) {
                    count += it->second;
                }
            }
        }
        
        return count;
    }
};
