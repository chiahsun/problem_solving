class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        
        def replace_word(word, roots):
            for i in range(1, len(word)):
                if word[:i] in roots:
                    return word[:i]
            return word
        
        roots = set(dict)
        strs = []
        begin = 0
        for i in range(0, len(sentence)+1):
            if i == len(sentence) or sentence[i] == ' ':
                if begin < i:
                    strs.append(replace_word(sentence[begin:i], roots))
                    begin = i+1
                if i != len(sentence) and sentence[i] == ' ':
                    strs.append(' ')

        return "".join(strs)
