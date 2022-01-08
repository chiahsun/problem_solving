#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int b, j;
    Task(int b, int j) : b(b), j(j) { }
    bool operator < (const Task & rhs) const {
        return j > rhs.j;
    }
};

int main() {
    int N;
    int posCase = 1;
    while ((scanf("%d", &N) == 1) && N > 0) {
        vector<Task> tasks;
        while (N--) {
            int b, j;
            scanf("%d %d", &b, &j);
            tasks.push_back(Task(b, j));
        }
        sort(tasks.begin(), tasks.end());
        int offset = 0, ans = 0;
        for (const auto & t : tasks) {
            offset += t.b;
            ans = max(ans, offset + t.j);
        }
        printf("Case %d: %d\n", posCase++, ans);
    }

    return 0;
}