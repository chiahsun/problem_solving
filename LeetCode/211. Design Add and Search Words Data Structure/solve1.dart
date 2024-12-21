class TrieNode {
    List<TrieNode?> nexts = List<TrieNode?>.filled(26, null);
    bool isEnd = false;
}

class WordDictionary {
  final root = TrieNode();

  WordDictionary() { }

  void addWord(String word) {
    TrieNode p = root;
    final codes = word.codeUnits;
    for (int i = 0; i < codes.length; ++i) {
        int c = codes[i] - 97;
        if (p.nexts[c] == null) {
            p.nexts[c] = TrieNode();
        }
        p = p.nexts[c]!;
        if (i == codes.length-1) p.isEnd = true;
    }
  }

  bool search(String word) {
    final N = word.length;
    final codes = word.codeUnits;
    bool dfs(TrieNode p, int pos) {
        if (pos >= N) return true;
        if (word[pos] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (p.nexts[i] != null) {
                    if (pos+1 >= N) { if ((p.nexts[i]!).isEnd) return true;  }
                    else if (dfs(p.nexts[i]!, pos+1)) { return true; }
                }
            }
            return false;
        }
        int c = codes[pos] - 97;
        if (p.nexts[c] == null) return false;
        if (pos == N-1) return (p.nexts[c]!).isEnd;
        return dfs(p.nexts[c]!, pos+1);
    }
    return dfs(root, 0);
  }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = WordDictionary();
 * obj.addWord(word);
 * bool param2 = obj.search(word);
 */
