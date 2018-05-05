class Trie:
    # Need to use dict/set; otherwise, we are iteraing all characters related to <= len(word) for each word query
    def __init__(self):
        self.m = {} # Charactor to Trie node
    
    def addWord(self, word):
        print('Add word', word)
        if len(word) == 0:
            self.m[None] = Trie()
            return
        
        if word[0] not in self.m:
            self.m[word[0]] = Trie()
            
        self.m[word[0]].addWord(word[1:])
        
    def findPrefix(self, word):
        print('findPrefix: ', word)
        cur = self

        prefix = []
        for c in word:
            if None in cur.m:
                break;
            elif not c in cur.m:
                return word
            else:
                prefix.append(c)
                cur = cur.m[c]

        return "".join(prefix)

    def printTree(self, ws):
        for c, child in self.m.items():
            print(ws, c, child)
            child.printTree(ws + "  ")
    
class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        t = Trie()
        for d in dict:
            t.addWord(d)
        t.printTree("")
            
        ans = []
        for s in sentence.split():
            ans.append(t.findPrefix(s))
            
        return " ".join(ans)
            
        
s = Solution()
print(s.replaceWords(["cat", "bat", "rat"], "the cattle was rattled by the battery  "))
print(s.replaceWords(["a", "aa", "aaa", "aaaa"], "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"))

