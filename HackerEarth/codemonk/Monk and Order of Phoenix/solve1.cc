// 3 5 4
// 1 1 2

// 3 5 
// 1 1 2 -> NO (stack 1 has min value 3 but stack 2 has max value 2)

// 3 5 1
// 1 1 2 -> YES (1, 2)

// 3 5
// 1 1 2 -> NO

// 3 5 
// 1 1 2 4 -> YES (stack 1 takes 3, stack 2 takes 4)

// We use binary search to find the least valid element in the following stacks.

// See: https://www.youtube.com/watch?v=Fad_AzJDk88 for official explanation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchGt(const std::vector<int> & nums, int target) {
	if (nums.empty()) { return -1; }
	if (target >= nums.back()) { return -1; }
	if (target < nums.front()) { return nums[0]; }

    int i = 0, k = nums.size()-1;
	while (i < k) {
		int mid = (i+k)/2;
		int midVal = nums[mid];
		if (midVal <= target) { i = mid+1; }
		else                 { k = mid; }
	}
	return nums[i];
}

bool solve(const vector<vector<int> > & nums, const vector<int> & minStack) {
	if (nums[0].empty()) { return false; }
	int cur = minStack.back();
	// int cur = *min_element(nums[0].begin(), nums[0].end());
	for (size_t i = 1; i < nums.size(); ++i) {
		int next = binarySearchGt(nums[i], cur);
		if (next > cur) { cur = next; }
		else           { return false; }
	}
	return true;
}

int main() {
	int N;
	cin >> N;	

    vector<vector<int> > nums(N);
	for (size_t i = 0; i < N; ++i) {
		int M;
		cin >> M;
		while (M--) {
			int x;
			cin >> x;
			nums[i].push_back(x);
		}
	}
	vector<int> minStack;
	int minVal = INT_MAX;
	for (auto x: nums[0]) {
		minVal = min(minVal, x);
		minStack.push_back(minVal);
	}
	int Q, k, h;
	cin >> Q;
	while (Q--) {
		int cmd;
		cin >> cmd;
		switch(cmd) {
			case 0:
			    cin >> k;
                if (!nums[k-1].empty()) {
					nums[k-1].pop_back();
					if (k == 1) {
						minStack.pop_back();
					}
				}
			    break;
			case 1:
			    cin >> k >> h;
				if (k == 1 || nums[k-1].empty() || (nums[k-1].back() <= h)) {
					nums[k-1].push_back(h);
					if (k == 1) {
						int minVal = h;
						if (!nums[0].empty()) {
							minVal = min(minVal, minStack.back());
						}
						minStack.push_back(minVal);
					}
				}
			    break;
			case 2:
			    printf(solve(nums, minStack) ? "YES" : "NO");
				cout << endl;
			    break;
			default:
			    break;
		}
	}
	return 0;
}
