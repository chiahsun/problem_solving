#include <iostream>
#include <vector>
using namespace std;

static const int int32Max = 2147483647;

int search(const std::vector<int> & nums, int mask) {
	if (nums.size() == 2) { return nums[0] ^ nums[1]; }
	if (nums.size() <= 1) { return int32Max; }
	if (mask == 0) { return 0; }

	std::vector<int> A, B;
	for (auto x: nums) {
		if ((x & mask) > 0) { A.push_back(x); }
		else               { B.push_back(x); }
	}
    return min(search(A, mask >> 1), search(B, mask >> 1));
}

int solve(const std::vector<int> & nums) {	
	return search(nums, 0x1 << 30);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> nums;
		while (N--) {
			int x;
			cin >> x;
			nums.push_back(x);
		}
		cout << (solve(nums)) << endl;
	}
	
}
