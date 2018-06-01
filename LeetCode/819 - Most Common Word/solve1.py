class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        banned = set(banned)
        d = collections.defaultdict(int)
        begin = 0
        max_count = 0
        max_word = ""
        N = len(paragraph)
        while begin < N:
            while begin < N and not paragraph[begin].isalpha(): 
                begin += 1
            if begin == N: 
                break
            end = begin+1
            while end < N and paragraph[end].isalpha():
                end += 1
            
            cur_word = paragraph[begin:end].lower()
            if not cur_word in banned:
                d[cur_word] += 1
                if (d[cur_word] > max_count):
                    max_count = d[cur_word]
                    max_word = cur_word
                    
            begin = end
        
        return max_word
        
