class TrieNode {
    bool isEnd = false;
    final nexts = List<TrieNode?>.filled(26, null);
    TrieNode? match(String s)   { return matchPos(s.codeUnitAt(0) - 97); }
    TrieNode? matchPos(int pos) {  return nexts[pos]; }
    bool noChild() { return nexts.every((e) => e == null); }
}

class Trie {
    final TrieNode root = TrieNode();
    void addWord(String s) {
        final codes = s.codeUnits.map((v) => v - 97);
        TrieNode p = root;
        for (final code in codes) {
            final next = p.matchPos(code);;
            if (next == null) {
                 p.nexts[code] = TrieNode();
            }
            p = p.nexts[code]!;
        }
        p.isEnd = true;
    }

    // Note we don't check here, s and its children (if exists) would be deleted
    void deleteWord(String s) {
        final codes = s.codeUnits.map((v) => v - 97).toList();
        TrieNode p = root;
        for (int i = 0; i < codes.length; ++i) {
            final code = codes[i];
            if (i == codes.length-1) {
                p.nexts[code] = null;
            } else {
                final next = p.matchPos(code);
                if (next != null) p = next;
                else              return;
            }
        }
    }

    void printWords() {
        List<String> cur = [];
        void dfs(TrieNode p) {
            if (p.isEnd) {
                final word = cur.join();
                print(word);
            }
            for (int i = 0; i < 26; ++i) {
                final next = p.nexts[i];
                if (next != null) {
                    cur.add(String.fromCharCode(i + 97));
                    dfs(next);
                    cur.removeLast();
                }
            }
        }
        dfs(root);
    }
}

class Solution {
  List<String> findWords(List<List<String>> board, List<String> words) {
    final Trie trie = Trie();
    final M = board.length, N = board.first.length;
    for (final word in words) trie.addWord(word);
    // trie.printWords();

    final dd = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    List<String> st = [];
    final res = Set<String>();
    // If some word is found and all its child is null, then remove it
    void dfs(TrieNode p, int x, int y) {
        final c = board[x][y];
        st.add(c);
        final curWord = st.join();
        board[x][y] = '-';
        if (p.isEnd) res.add(curWord);
        for (final [dx, dy] in dd) {
            final nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && board[nx][ny] != '-') {
                final nextC = board[nx][ny];
                final nextNode = p.match(nextC);
                if (nextNode != null) {
                    dfs(nextNode, nx, ny);
                }
            }
        }
        st.removeLast();
        board[x][y] = c;
        if (p.isEnd && p.noChild()) {
            trie.deleteWord(curWord);
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < N; ++k) {
            final nextNode = trie.root.match(board[i][k]);
            if (nextNode != null) {
                dfs(nextNode, i, k);
            }
        }
    }

    return List.from(res);
  }
}
