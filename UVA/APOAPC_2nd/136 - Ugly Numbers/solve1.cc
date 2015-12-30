#include <cstdio>
#include <queue>
#include <vector>
typedef unsigned long long ull;
struct Compare {
    bool operator () (const ull & lhs, const ull & rhs) const
        { return lhs > rhs; }
};

int main() {
    
    std::vector<ull> vecUgly;
    std::priority_queue<ull, std::vector<ull>, Compare> q((Compare()));

    q.push(1);

    do {
        ull top = q.top(); q.pop();
        if (vecUgly.size() == 0 or top != vecUgly.back()) {
//            printf("The %lu'th ugly number is %llu.\n", vecUgly.size()+1, top);
            vecUgly.push_back(top);
            q.push(top * 2);
            q.push(top * 3);
            q.push(top * 5);
        }

    } while (vecUgly.size() < 1500);

    printf("The 1500'th ugly number is %llu.\n", vecUgly.back());
    return 0;
}
