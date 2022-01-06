#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int mod = 100000;

struct Tuple { 
	int leftValue, pos, oriPos;
	Tuple(int l, int p, int o) : leftValue(l), pos(p), oriPos(o) { }
	bool operator < (const Tuple& rhs) const {
		int lm = leftValue % mod;
		int rm = rhs.leftValue % mod;
		if (lm != rm) {
			return lm < rm;
		}
        return pos < rhs.pos;
    }
};

void solve(const vector<int> & nums) {
	vector<Tuple> tuples;
	for (size_t i = 0; i < nums.size(); ++i) {
		tuples.push_back(Tuple(nums[i], i, i));
	}
	while (true) {
        std::sort(tuples.begin(), tuples.end());
		for (size_t i = 0; i < tuples.size(); ++i) {
			if (i != 0) { cout << " "; }
			cout << nums[tuples[i].oriPos];
		}
		cout << endl;
		bool hasNext = false;
		for (size_t i = 0; i < tuples.size(); ++i) {
			int nextLeftValue = tuples[i].leftValue/mod;
			tuples[i].leftValue = nextLeftValue;
			if (nextLeftValue > 0) { hasNext = true; }
			tuples[i].pos = i;
		}
		if (!hasNext) { break; }
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> nums;
	while (N--) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	solve(nums);
}