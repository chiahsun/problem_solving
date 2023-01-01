#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using std::string;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::stringstream ss(str);

        std::vector<string> v;
        std::string s;
        while (ss >> s)
            v.push_back(s);

        if (pattern.size() != v.size())
            return false;

        std::map<char, std::string> m;
        std::set<std::string> used;
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            if (m.find(c) == m.end()) {
                if (used.find(v[i]) != used.end())
                    return false;
                m.insert(std::make_pair(c, v[i]));
                used.insert(v[i]);
            } else if (m[c] != v[i])
                return false;
        }

        return true;
    }
};

int main() {
    std::cout << (Solution().wordPattern("abba", "dog cat cat dog")) << std::endl;
    std::cout << (Solution().wordPattern("abba", "dog dog dog dog")) << std::endl;
    return 0;
}
