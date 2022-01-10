#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b) {
	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}

uintmax_t lcm(int a, int b) {
	return (uintmax_t)a / gcd(a, b) * b ;
}

int solve(const vector<int>& cnts, int P, int Q) {
	int ans = cnts[P] + cnts[Q];
	uintmax_t lcmVal = lcm(P, Q);
	if (lcmVal < cnts.size()) {
		ans -= cnts[lcmVal];
	}
	return ans;
}

int main() {
	int N;
	cin >> N;	
	map<int, int> m;
	while (N--) {
		int x;
		cin >> x;
		++m[x];
	}
	vector<int> cnts(200000+1);
	for (const auto& [a, cnt]: m) {
		int d = 1;
		while (d * d <= a) {
			if (a % d == 0) {
                cnts[d] += cnt;
			    int another = a/d;
			    if (another != d) {
				    cnts[another] += cnt;
			    }
			}
			++d;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int P, Q;
		cin >> P >> Q;
		cout << solve(cnts, P, Q) << endl;
	}
}

