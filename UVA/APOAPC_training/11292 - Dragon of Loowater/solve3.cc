#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while(scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {
        vector<int> dragons, warriors;
        int x;
        while (N--) { cin >> x; dragons.push_back(x); }
        while (M--) { cin >> x; warriors.push_back(x); }

        int cost = 0;
        bool failed = (M < N);
        if (!failed) {
             sort(dragons.begin(), dragons.end());
             sort(warriors.begin(), warriors.end());
             int i = 0;
             int k = 0;
             while (k < warriors.size() && i < dragons.size()) {
                  if (warriors[k] >= dragons[i]) {
                      cost += warriors[k]; i++; k++;
                  } else {
                      k++;
                  }
             }
             if (i < dragons.size()) { failed = true; }
        }
        if (failed) { cout << "Loowater is doomed!" << endl; }
        else        { cout << cost << endl; }
    }
    return 0;
}