class Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        d = {}
        for ans in answers:
            key = ans+1
            if not key in d:
                d[key] = 1
            else:
                d[key] += 1
        
        total = 0
        for nsame, count in d.items():
            while count > 0:
                total += nsame
                count -= nsame
        return total
            
