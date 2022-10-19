#  1  2  3  4  5 -> 3
#  2  3  4  5  6 -> 2
#  
#  1 2 3 4 -> 2
#  2 3 4 5 -> 2
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low + (1 if low % 2 == 1 else 0) 
            + (1 if high % 2 == 1 else 0)) // 2
