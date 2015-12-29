#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

char buf[80+5];

int cnt[26+5];
std::string normalize(const std::string & s) {
    char buf2[80+5];
    for (int i = 0; i < s.size(); ++i) {
        buf2[i] = tolower(s[i]);
    }
    std::sort(buf2, buf2+s.size());
    return std::string(buf2, s.size());
}

int main() {
    std::vector<std::string> v;
    std::map<std::string, int> m;
    std::map<std::string, int>::iterator it;

    while (scanf("%s", buf) == 1 && strncmp(buf, "#", 1)) {
        std::string s(buf);
        v.push_back(s);
        std::string ns(normalize(s));
        
        if ((it = m.find(ns)) == m.end())
            m.insert(std::make_pair(ns, 1));
        else
            ++(it->second);
    }

    std::set<std::string> s;
    for (const auto & str : v) {
        if (m[normalize(str)] == 1) {
            s.insert(str);
        }
    }
    for (const auto & str : s) {
        printf("%s\n", str.c_str());
    }
    return 0;
}
