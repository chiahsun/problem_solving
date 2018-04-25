#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<std::string> v[100];
    const int half_count = n/2;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        string s;
        cin >> x >> s;
        if (a0 < half_count) {
            v[x].push_back("-");
        } else {
            v[x].push_back(s);
        }
    }
    for (int i = 0, first = 1; i < sizeof(v)/sizeof(v[0]); ++i) {
        if (!v[i].empty()) {
            for (const std::string & s : v[i]) {
                std::cout << (first ? "" : " ") << s;
                if (first) first = 0;
            }
        }
    }
    return 0;
}

