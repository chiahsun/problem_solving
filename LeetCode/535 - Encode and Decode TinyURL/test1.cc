#include <iostream>
#include <string>
#include <map>

using std::string;

class Solution {
    std::map<std::string, std::string> m_;
public:
    static const std::string PREFIX;
    
    static char intToChar(int i) {
        i %= 10 + 26 + 26;
        std::cout << "i = " << i << std::endl;
        if (i < 10) return '0' + i;
        i -= 10;
        if (i < 26) return 'a' + i;
        i -= 26;
        if (i < 26) return 'A' + i;
        
        return '-'; // Should not happen
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        const int M = 6;
        int value[M] = {0};
        for (int i = 0; i < longUrl.size(); ++i) {
            value[(i * 7)%M] += longUrl[i];
        }
        
        std::string s(M, 'a');
        for (int i = 0; i < M; ++i)
            s[i] = intToChar(value[i]);
        if (m_.find(s) == m_.end()) {
            m_.insert(std::make_pair(s, longUrl));
            return PREFIX + s;
        }
        return encode(s);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_[shortUrl.substr(PREFIX.size(), shortUrl.size())];
    }
};

const std::string Solution::PREFIX = "http://tinyurl.com/";
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

void test_tinyurl(const std::string & input) {
    Solution s;
    std::string shortUrl = s.encode(input);
    std::cout << shortUrl << std::endl;
    std::cout << s.decode(shortUrl) << std::endl;
}

int main() {
    test_tinyurl("https://leetcode.com/problems/design-tinyurl");
    test_tinyurl("https://leetcode.com/problems/encode-and-decode-tinyurl/description/");
    return 0;
}
