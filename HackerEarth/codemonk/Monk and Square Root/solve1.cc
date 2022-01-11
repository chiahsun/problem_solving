#include <iostream>

using namespace std;

int solve(long long N, long long M) {
	for (long long i = 0; i <= M/2; ++i) {
		if (((i*i) % M) == N) {
			return i;
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << solve(N, M) << endl;
	}
	return 0;
}
