class TrieNode {
    bool end = false;
    List<TrieNode?> nexts = List<TrieNode?>.filled(26, null);
    TrieNode();
}

class Trie {
  final root = TrieNode();
  Trie() { }

  static List<int> getCodes(String s) {
    return s.codeUnits.map((v) => v-97).toList();
  }

  void insert(String word) {
    final codes = Trie.getCodes(word);
    var p = root;
    for (int i = 0; i < codes.length; ++i) {
        final c = codes[i];
        if (p.nexts[c] == null) {
            p = p.nexts[c] = TrieNode();
        } else {
            p = p.nexts[c]!;
        }
        if (i == codes.length-1) p.end = true;
    }
  }

  bool searchAux(String word, bool checkEnd) {
    final codes = Trie.getCodes(word);
    var p = root;
    for (int i = 0; i < codes.length; ++i) {
        final c = codes[i];
        if (p.nexts[c] == null) return false;
        p = p.nexts[c]!;
        if (i == codes.length-1)
            return checkEnd ? p.end : true;
    }
    return false;
  }

  bool search(String word) {
    return searchAux(word, true);
  }

  bool startsWith(String prefix) {
    return searchAux(prefix, false);
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = Trie();
 * obj.insert(word);
 * bool param2 = obj.search(word);
 * bool param3 = obj.startsWith(prefix);
 */
