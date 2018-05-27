#include <algorithm>

const int MAX_DISTANCE = 100001;

std::vector<int> get_fibs() {
    std::vector<int> fibs{1, 2};
    while (true) {
        int N = fibs.size();
        int cur = fibs[N-1] + fibs[N-2];
        if (cur < MAX_DISTANCE)
            fibs.push_back(cur);
        else
            break;
    }
    std::reverse(fibs.begin(), fibs.end());
    return fibs;
}

void visit(int cur, int cur_cost, std::vector<int> & costs,
           const std::vector<int> & A, 
           const std::vector<int> & fibs) {
    if (cur != -1) {
        if (costs[cur] != -1 && costs[cur] <= cur_cost) return;
        costs[cur] = cur_cost;
    }
    
    for (int fib : fibs) {
        int next = cur + fib;
        // if (next >= costs.size()) break;
        if (next == A.size() || (next < A.size() && A[next])) {
            visit(next, cur_cost+1, costs, A, fibs);
        }
    }
}

int solution(vector<int> &A) {
    const int N = A.size()+1;
    std::vector<int> costs(N, -1);
    std::vector<int> fibs = get_fibs();
    visit(-1, 0, costs, A, fibs);
    return costs.back();
}
