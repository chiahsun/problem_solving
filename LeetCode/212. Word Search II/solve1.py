class TrieNode:
    @staticmethod
    def get_pos(c):
        return ord(c) - ord('a')

    def __init__(self):
        self.children = [None] * 26
        self.isEnd = False
        self.children_cnt = 0

    def has_next(self, c):
        return self.children[TrieNode.get_pos(c)] is not None

    def get_next(self, c):
        return self.children[TrieNode.get_pos(c)]

    def is_end(self):
        return self.isEnd

    def remove(self, word):
        if not word:
            self.isEnd = False
            return self.children_cnt == 0
            
        c = word[0]
        pos = TrieNode.get_pos(c)
        can_remove = self.children[pos].remove(word[1:])
        if can_remove:
            self.children[pos] = None
            self.children_cnt -= 1
        return self.children_cnt == 0 and not self.isEnd


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def put(self, word):
        p = self.root
        for c in word:
            pos = TrieNode.get_pos(c)
            if p.children[pos] is None:
                p.children[pos] = TrieNode()
                p.children_cnt += 1
            p = p.children[pos]
        p.isEnd = True    

    def get_root(self):
        return self.root

    def remove_word(self, word):
        self.root.remove(word)


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        M, N = len(board), len(board[0])
        trie = Trie()
        for word in words:
            trie.put(word)
        root = trie.get_root()

        res = []
        visited = [[False] * N for _ in range(M)]
        def dfs(x, y, p, st):
            c = board[x][y]
            visited[x][y] = True
            st.append(c)
            p = p.get_next(c)
            
            if p.is_end():
                word = "".join(st)
                res.append(word)
                trie.remove_word(word)
            for dx, dy in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                nx, ny = x+dx, y+dy
                if nx >= 0 and nx < M and ny >= 0 and ny < N and not visited[nx][ny] and p.has_next(board[nx][ny]):
                    dfs(nx, ny, p, st)
            st.pop()
            visited[x][y] = False


        for x in range(M):
            for y in range(N):
                if root.has_next(board[x][y]):
                    dfs(x, y, root, [])
        return res

