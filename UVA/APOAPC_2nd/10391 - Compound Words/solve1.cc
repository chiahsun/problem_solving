#include <cstdio>
#include <string>
#include <vector>
#include <set>

char buf[200];

bool is_prefix(const std::string & prefix, const std::string & s) {
    if (prefix.size() >= s.size())
        return false;
    for (int i = 0; i < prefix.size(); ++i)
        if (prefix[i] != s[i])
            return false;
    return true;
}

int main() {
    std::vector<std::string> vec;
    std::set<std::string> set;
    std::set<std::string> compounds;

    while (scanf("%s", buf) == 1) {
        std::string s(buf);
        vec.push_back(s);
        set.insert(s);
    }

    for (int i = 0; i < vec.size(); ++i) {
        const std::string s1 = vec[i];

        for (int k = i+1; k < vec.size(); ++k) {
            const std::string s2 = vec[k];
            if (is_prefix(s1, s2)) {
                const std::string s3 = s2.substr(s1.size(), s2.size() - s1.size());
                if (set.count(s3))
                    compounds.insert(s2);
            } else {
                break;
            }
        }
                    
    }

    for (auto & s : compounds)
        printf("%s\n", s.c_str());

    return 0;
}
