class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    @staticmethod
    def get_pos(c):
        return ord(c) - ord('a')

    def put(self, word, cur):
        if not word:
            self.cnt = 1
            return self.cnt
        ori = word
        nxt = cur + word[0]
        pos = TrieNode.get_pos(word[0])
        word = word[1:]
        if self.children[pos]:
            if word:
                self.cnt -= self.children[pos].cnt
                self.children[pos].put(word, nxt)
                self.cnt += self.children[pos].cnt
        else:
            p = self.children[pos] = TrieNode()
            p.put(word, nxt)
            self.cnt += p.cnt
        return self.cnt


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def put(self, word):
        self.root.put(word, "")

    def get_prefix(self, word):
        p = self.root
        for i, c in enumerate(word):
            p = p.children[TrieNode.get_pos(c)]
            if p.cnt == 1:
                return word[:i + 1]
        return word


class Solution:
    # @param A : list of strings
    # @return a list of strings
    def prefix(self, A):
        trie = Trie()
        for word in A:
            trie.put(word)

        return [trie.get_prefix(word) for word in A]
