class Trie:

    class TrieNode:
        def __init__(self, c=None, end=False):
            self.c = c
            self.end = end
            self.nexts = []

    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word: str) -> None:
        p = self.root
        for i, c in enumerate(word):
            pos = -1
            for k, nxt in enumerate(p.nexts):
                if nxt.c == c:
                    pos = k
                    break
            if pos == -1:
                new_node = self.TrieNode(c=c)
                p.nexts.append(new_node)
                p = new_node
            else:
                p = p.nexts[pos]
            if i == len(word)-1:
                p.end = True

    def find_node(self, prefix: str) -> TrieNode:
        p = self.root
        for i, c in enumerate(prefix):
            ok = False
            for nxt in p.nexts:
                if nxt.c == c:
                    ok = True
                    p = nxt
                    break
            if not ok:
                return None
        return p

    def search(self, word: str) -> bool:
        nd = self.find_node(word)
        return nd and nd.end


    def startsWith(self, prefix: str) -> bool:
        return self.find_node(prefix)



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
