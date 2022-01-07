#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using elementValueType = unsigned long long;

struct Pair {
	elementValueType val;
	int index;
	Pair(elementValueType v, int i) : val(v), index(i) { }
};

std::vector<int> solve(const std::vector<elementValueType> & nums) {
	vector<int> ans(nums.size());

    // A[x] part
	stack<Pair> st;
	for (size_t i = 0; i < nums.size(); ++i) {
		while (!st.empty()) {
			Pair rightMost = st.top();
			if (rightMost.val > nums[i]) {
				ans[i] += rightMost.index;
				break;
			} else {
				st.pop();
			}
		}
		if (st.empty()) { ans[i] += -1; }
		st.push(Pair(nums[i], i+1));
	}

	// A[y] part
	st = {};
	for (int i = nums.size()-1; i >= 0; --i) {
		while (!st.empty()) {
			Pair leftMost = st.top();
			if (leftMost.val > nums[i]) {
				ans[i] += leftMost.index;
				break;
			} else {
				st.pop();
			}
		}
		if (st.empty()) { ans[i] += -1; }
		st.push(Pair(nums[i], i+1));
	}

	return ans;
}

int main() {
	int N;
	cin >> N;
	vector<elementValueType> nums;
	while (N--) {
		elementValueType x;
		cin >> x;
		nums.push_back(x);
	}
	vector<int> ans = solve(nums);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i != 0) { cout << " " ; }
		cout << ans[i];
	}
	cout << endl;
}
