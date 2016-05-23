class Solution {
public:
    bool is_vowel(char c) {
        int vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < sizeof(vowels)/sizeof(vowels[0]); ++i)
            if (vowels[i] == c)
                return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int i = 0, k = s.size()-1;
        
        while(i < k) {
            while ((not is_vowel(s[i])) and i < s.size()) ++i;
            while ((not is_vowel(s[k])) and k >= 0) --k;
            if (i >= k) break;
            std::swap(s[i], s[k]);
            ++i, --k;
        }
        return s;
    }
};
