#  1  2  3  4  5 -> 3
#  2  3  4  5  6 -> 2
#  
#  1 2 3 4 -> 2
#  2 3 4 5 -> 2
class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if (high - low) % 2 == 1:
            return (1 + high - low) // 2
        else:
            return (1 + high - low) // 2 + (1 if low % 2 == 1 else 0)
