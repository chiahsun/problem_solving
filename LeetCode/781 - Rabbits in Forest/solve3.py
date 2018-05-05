class Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        d = {}
        total = 0
        for ans in answers:
            key = ans+1
            if 0 == d.get(key, 0):
                d[key] = key-1
                total += key
            else:
                d[key] -= 1
                
        return total
