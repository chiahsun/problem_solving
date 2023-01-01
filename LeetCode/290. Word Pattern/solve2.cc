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
        string m[26];
        
        int begin = 0, end = 0;
        int i_pattern = 0;
        while (begin < str.size()) {
            end = begin+1;
            while (end < str.size() and str[end] != ' ') ++end;
            std::string word = str.substr(begin, end-begin);
           
            std::cout << word << std::endl; 
            if (word.empty()) 
                break;
                
            int pos = pattern[i_pattern] - 'a';
            if (not m[pos].empty() and m[pos] != word) 
                return false;
            if (m[pos].empty()) 
                m[pos] = word;
            begin = end+1;
            ++i_pattern;
        }

        if (i_pattern < pattern.size())
            return false;
        
        std::vector<string> v;
        for (int i = 0; i < 26; ++i)
            if (not m[i].empty())
                v.push_back(m[i]);
                
        std::sort(v.begin(), v.end());
        
        for (int i = 1; i < v.size(); ++i)
            if (v[i-1] == v[i])
                return false;
 
        return true;
    }
};

int main() {
    std::cout << (Solution().wordPattern("abba", "dog cat cat dog")) << std::endl;
    std::cout << (Solution().wordPattern("abba", "dog dog dog dog")) << std::endl;
    std::cout << (Solution().wordPattern("jquery", "jquery")) << std::endl;
    return 0;
}
