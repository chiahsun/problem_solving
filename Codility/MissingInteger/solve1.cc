#include <unordered_set>

int solution(vector<int> &A) {
    std::unordered_set<int> s;
    for (int a : A) s.insert(a);
    
    for (int i = 1; i <= 100001; ++i) {
        if (s.count(i) == 0) return i;
    }
    
    return -1;
}
