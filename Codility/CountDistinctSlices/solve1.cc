// 3 4 5 5 2
// 3 4 5       4*3/2 = 6
//       5 2   3*2/2 = 3

// 3 4 5 4 2
// 3 4 5       4*3/2 = 6
//     5 4 2   4*3/2 = 6 - 1 = 5  (-) 5

const int MAX_VALUE = 1000000000;

int get_count(long long x) {
    long long res = (x+1)*x/2;
    if (res > MAX_VALUE) res = MAX_VALUE+1;
    return res;
}

int solution(int M, vector<int> &A) {
    int begin = 0, end = -1, N = A.size(), ans = 0;
    for (int i = 0; i < A.size(); ++i) M = std::max(M, A[i]);
    bool used[M+1];
    for (int i = 0; i < M+1; ++i) used[i] = false;

    int last_end;
    while (true) {
        last_end = end;
        while (end+1 < N && !used[A[end+1]] ) {
            ++end;
            used[A[end]] = true;
        }
        /*for (int i = begin; i <= end; ++i) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
        if (begin <= last_end) {
            std::cout << " (-)";
            for (int i = begin; i <= last_end; ++i) {
                std::cout << A[i] << " ";
            }
            std::cout << std::endl;
        }*/
        ans += get_count(end-begin+1);
        if (ans > MAX_VALUE) return MAX_VALUE;
        if (begin <= last_end) ans -= get_count(last_end-begin+1);
        if (end+1 == N) break;
        int next = A[end+1];
        while (A[begin] != next) {
            used[A[begin]] = false;
            ++begin;
        }
        used[A[begin]] = false;
        ++begin;
    }
    
    return ans;
}
