struct Candidate {
    int x_, y_, value_;
    Candidate(int x, int y, int value) : x_(x), y_(y), value_(value) { }
    bool operator < (const Candidate & other) const {
        if (value_ != other.value_) return value_ > other.value_;
        return false;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int N = matrix.size();
        const int max_value = matrix[N-1][N-1];
        if (k == 1) return matrix[0][0];
        if (k == N*N) return max_value;
        
        std::priority_queue<Candidate> pq;
        pq.push(Candidate(0, 0, matrix[0][0]));
        
        int cur = 1;
        while (!pq.empty()) {
            Candidate top = pq.top(); pq.pop();
            if (cur == k) return top.value_;
            int x[2] = {top.x_+1, top.x_};
            int y[2] = {top.y_, top.y_+1};
            for (int i = 0; i < 2; ++i) {
                int curx = x[i], cury = y[i];
                if (curx < N && cury < N && matrix[curx][cury] != max_value) {
                    pq.push(Candidate(curx, cury, matrix[curx][cury]));
                    matrix[curx][cury] = max_value;
                }
            }
            ++cur;
        }
        
        return max_value;
    }
}; 
