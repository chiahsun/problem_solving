class TrieNode {
    bool isEnd = false;
    final nexts = List<TrieNode?>.filled(26, null);
    TrieNode? match(String s) {
        return nexts[s.codeUnitAt(0) - 97];
    }
    TrieNode? matchPos(int pos) {
        return nexts[pos];
    }
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
    // TODO: If some word is found, remove it
    // but we cannot remove a TrieNode if all its leaf removed.
    // sad saddy
    // If sad is removed buy we may still have saddy
    void dfs(TrieNode p, int x, int y) {
        final c = board[x][y];
        st.add(c);
        board[x][y] = '-';
        if (p.isEnd) {
            res.add(st.join());
        }
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
