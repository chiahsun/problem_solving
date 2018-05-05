class DictTree:
    def __init__(self, c, successor):
        self.c = c
        self.successor = successor
        
    def findPrefix(self, word, cur_pos):
        if cur_pos >= len(word):
            return None
        if self.c is not None and word[cur_pos] != self.c:
            return None
                
        if None in self.successor:
            return word[:cur_pos+1]
        
        for suc in self.successor:
            if self.c is not None:
                res = suc.findPrefix(word, cur_pos+1)
            else:
                res = suc.findPrefix(word, cur_pos)
            if res is not None:
                return res
        return None
    
    def addWord(self, word, pos):
        if pos >= len(word):
            return
        if self.c is not None:
            if self.c != word[pos]:
                return
            if len(word) == pos+1:
                if not None in self.successor:
                    self.successor.append(None)
                return
            pos += 1
            
        for suc in self.successor:
            if suc is not None and suc.c == word[pos]:
                suc.addWord(word, pos)
                return
        suc = DictTree(word[pos], [])
        suc.addWord(word, pos)
        self.successor.append(suc)

    def printTree(self, ws):
        print(ws, 'Cur: ', self.c, ', ', self.successor)
        for suc in self.successor:
            if suc is not None:
                suc.printTree(ws + "  ")
        
class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        
        def build_dict_tree(dict):
            root = DictTree(None, [])
            for word in dict:
                root.addWord(word, 0)
            return root
        
        def replace_word(word, dict_tree):
            prefix = dict_tree.findPrefix(word, 0)
            return prefix if prefix is not None else word
        
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
#print(s.replaceWords(["a", "aa", "aaa", "aaaa"], "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"))

