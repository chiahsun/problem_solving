class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        const int N = n+1;
        std::map<char, int> m;
        for (char task : tasks) {
            if (m.count(task)) { ++m[task]; }
            else               { m[task] = 1; }
        }
        
        std::priority_queue<int> pq;
        for (const auto & elem : m) {
            pq.push(elem.second);
        }
        
        int cycles = 0;
        std::vector<int> nextRound;
        while (!pq.empty()) {
            int cur_cycles = 0;
            for (int i = 0; i < N; ++i) {
                if (pq.empty()) {
                    if (nextRound.empty()) break;
                    else                   cur_cycles = N;
                } else {
                    int top = pq.top(); pq.pop();
                    if (top > 1) {
                        nextRound.push_back(top-1);
                    }
                    ++cur_cycles;
                }
            }
            cycles += cur_cycles;
            for (int elem : nextRound) {
                pq.push(elem);
            }
            nextRound.clear();
        }
        
        return cycles;
    }
};

