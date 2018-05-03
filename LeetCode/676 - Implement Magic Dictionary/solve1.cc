class MagicDictionary {
    std::map<int, std::vector<std::string> > m_;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        m_.clear();
        for (const auto & s : dict) {
            m_[s.size()].push_back(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        auto it = m_.find(word.size());
        if (it != m_.end()) {
            for (const auto & s : it->second) {
                int ndif = 0;
                for (int i = 0; i < s.size(); ++i) {
                    if (word[i] != s[i]) ++ndif;
                    if (ndif > 1) break;
                }
                if (ndif == 1)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
