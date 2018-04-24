#include <vector>
#include <map>
#include <queue>
#include <iostream>

using std::vector;
#include "solve1.h"

void test(const char A[], int size, int N) {
    std::vector<char> tasks(A, A+size);
    Solution s;
    std::cout << s.leastInterval(tasks, N) << std::endl;
}

int main() {
    {
        const char A[] = {'A', 'A', 'A', 'B', 'B' , 'B'};
        const int N = 2;
        const int answer = 8;
        test(A, sizeof(A)/sizeof(A[0]), N);
    }
    {
        const char A[] = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        const int N = 2;
        const int answer = 16;
        test(A, sizeof(A)/sizeof(A[0]), N);
    }
    return 0;
}
