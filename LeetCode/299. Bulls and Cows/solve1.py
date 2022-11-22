class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        def getPos(c):
            return ord(c) - ord('0')
            
        cntS, cntG = [0] * 10, [0] * 10
        
        secret, guess = list(secret), list(guess)
        
        for i in range(len(secret)):
            cntS[getPos(secret[i])] += 1
            cntG[getPos(guess[i])] += 1
        
        A, B = 0, 0
        
        for i in range(len(cntS)):
            B += min(cntS[i], cntG[i])
        
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                A += 1
        B -= A
        
        return str(A) + "A" + str(B) + "B"
        
