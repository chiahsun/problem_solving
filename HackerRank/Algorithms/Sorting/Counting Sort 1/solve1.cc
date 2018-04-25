#include <bits/stdc++.h>

using namespace std;

vector <int> countingSort(vector <int> arr) {
    // Complete this function
    int cnt[100] = {0};
    for (int a : arr) {
        ++cnt[a];
    }
    return std::vector<int>(cnt, cnt+sizeof(cnt)/sizeof(cnt[0]));
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

