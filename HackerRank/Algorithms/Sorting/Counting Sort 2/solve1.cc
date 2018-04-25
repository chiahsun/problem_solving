#include <bits/stdc++.h>

using namespace std;

vector <int> countingSort(vector <int> arr) {
    // Complete this function
    int cnt[100] = {0};
    for (int a : arr) {
        ++cnt[a];
    }
    std::vector<int> ans;
    ans.reserve(arr.size());
    for (int i = 0; i < sizeof(cnt)/sizeof(cnt[0]); ++i) {
        int cur_cnt = cnt[i];
        if (cur_cnt) {
            for (int k = 0; k < cur_cnt; ++k) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = countingSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

