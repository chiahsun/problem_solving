class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
            
        s = [True] * n
        s[0] = s[1] = False
        
        for i in range(3, n, 2):
            if s[i]:
                for k in range(i+i+i, n, 2*i):
                    s[k] = False
                    
        n_prime = 1
        
        for i in range(3, n, 2):
            n_prime += (1 if s[i] else 0)
        
        return n_prime
