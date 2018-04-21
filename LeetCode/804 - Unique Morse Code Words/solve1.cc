class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static const char* const code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        std::set<std::string> s;
        for (const std::string & wd : words) {
            std::string res;
            for (int i = 0; i < wd.size(); ++i) {
                res += code[wd[i] - 'a'];
            }
            s.insert(res);
        }
        
        return s.size();
    }
};
