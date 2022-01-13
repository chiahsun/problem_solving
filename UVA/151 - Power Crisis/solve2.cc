#include <iostream>

using namespace std;

int tru(int x, int N) {
    if (x > N) {
        x -= (N * ((x-1) / N));
    }
    return x;
}

int JJ(int N, int K) {
    int prev = 1;
    for (int i = 2; i <= N; ++i) {
        if (i == N) {
            return tru(prev + 1, i);
        }
        prev = tru(prev + K, i);
    }
    return 0;
}


int main() {
    int N;
    while ((cin >> N) && N) {
        for (int i = 1; i <= N*N; ++i) { // I am not sure about the end condition ...
            if (JJ(N, i) == 13) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}