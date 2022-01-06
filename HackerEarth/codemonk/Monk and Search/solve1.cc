#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchGeq(const std::vector<int> & nums, int target) {
	if (target > nums.back()) { return 0; }
	if (target <= nums.front()) { return nums.size(); }
	int i = 0, k = nums.size()-1;
	while (i < k) {
		int mid = (i+k)/2;
		int midVal = nums[mid];
		if (midVal < target) { i = mid+1; }
		else               { k = mid; }
	}
	return nums.size()-i;
}

int binarySearchGt(const std::vector<int> & nums, int target) {
	if (target >= nums.back()) { return 0; }
	if (target < nums.front()) { return nums.size(); }
	int i = 0, k = nums.size()-1;
	while (i < k) {
		int mid = (i+k)/2;
		int midVal = nums[mid];
		if (midVal <= target) { i = mid+1; }
		else               { k = mid; }
	}
	return nums.size()-i;
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
	std::sort(nums.begin(), nums.end());
	cin >> N;
	while (N--) { 
		int q, target;
		cin >> q >> target;
		if (q == 0) {
			cout << binarySearchGeq(nums, target) << endl;
		} else {
            cout << binarySearchGt(nums, target) << endl;
		}
	}
	return 0;
}
