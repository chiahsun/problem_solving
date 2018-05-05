class DictTree:
    def __init__(self, c, successor):
        self.c = c
        self.successor = successor
        
    def findPrefix(self, word, prefix):
        if not word:
            return None
        if word[0] != self.c:
            return None
        
        cur_prefix = "".join([prefix, self.c])
        
        if None in self.successor:
            return cur_prefix
        
        for suc in self.successor:
            res = suc.findPrefix(word[1:], cur_prefix)
            if res:
                return res
        return None
    
    def addWord(self, word):
        print("Add word", word)
        if not word:
            return
        if self.c != word[0]:
            return
        if len(word) == 1:
            if not None in self.successor:
                self.successor.append(None)
            return
        
        for suc in self.successor:
            if suc is not None and suc.c == word[1]:
                suc.addWord(word[1:])
                return
        suc = DictTree(word[1], [])
        suc.addWord(word[1:])
        self.successor.append(suc)

    def printTree(self, ws):
        print(ws, "Cur ", self.c, self.successor)
        for suc in self.successor:
            if suc:
                suc.printTree(" " + ws)
        
        
class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        
        def build_dict_tree(dict):
            root = DictTree(" ", [])
            for word in dict:
                root.addWord("".join([" ", word]))
            return root
        
        def replace_word(word, dict_tree):
            prefix = dict_tree.findPrefix("".join([" ", word]), "")
            if prefix:
                return prefix[1:]
            return word
        
        dict_tree = build_dict_tree(dict)
        dict_tree.printTree("")
        strs = []
        begin = 0
        for i in range(0, len(sentence)+1):
            if i == len(sentence) or sentence[i] == ' ':
                if begin < i:
                    strs.append(replace_word(sentence[begin:i], dict_tree))
                    begin = i
                if i != len(sentence) and sentence[i] == ' ':
                    while i < len(sentence) and sentence[i] == ' ':
                        i += 1
                    strs.append(sentence[begin:i])
                    begin = i

        return "".join(strs)

s = Solution()
print(s.replaceWords(["cat", "bat", "rat"], "the cattle was rattled by the battery  "))
print(s.replaceWords(["a", "aa", "aaa", "aaaa"], "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"))
