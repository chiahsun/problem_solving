#include <algorithm>

int solution(vector<int> &A) {
    int cnt = 0, last = 0, N = A.size(), index = -1;
    for (int a : A) {
        if (cnt == 0) {
            last = a;
            cnt = 1;
        } else {
            if (a == last) ++cnt;
            else --cnt;
        }
    }
    cnt = 0;
    for (int i = 0; i < A.size(); ++i) {
        int a = A[i];
        if (a == last) {
            ++cnt;
            if (index == -1) index = i;
        }
        if (cnt > N/2) return index;
    }
    return -1;
}
