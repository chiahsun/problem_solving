#include <bits/stdc++.h>

using namespace std;

vector <int> closestNumbers(vector <int> arr) {
    std::vector<int> ans;
    ans.push_back(arr[0]);
    ans.push_back(arr[1]);
    
    // Complete this function
    std::sort(arr.begin(), arr.end());
    int dmin = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); ++i) {
        int last = arr[i-1];
        int cur = arr[i];
        int d = cur - last;
        if (d <= dmin) {
            if (d < dmin) {
                dmin = d;
                ans.clear();
            }
            ans.push_back(last);
            ans.push_back(cur);
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
    vector <int> result = closestNumbers(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

