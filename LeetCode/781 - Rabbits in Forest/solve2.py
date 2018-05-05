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
        for key, count in d.items():
            total += (count//key) * key
            if count % key != 0:
                total += key
                
        return total
            
