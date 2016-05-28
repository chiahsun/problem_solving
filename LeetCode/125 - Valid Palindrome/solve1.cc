class Solution {
public:
    bool isPalindrome(string s) {
        string word;
        for (const char & c : s)
            if (isalnum(c))
                word.push_back(c);
        for (int i = 0; i < word.size()/2; ++i)
            if (tolower(word[i]) != tolower(word[word.size()-i-1]))
                return false;
        return true;
    }
};
