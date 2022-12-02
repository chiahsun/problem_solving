class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        n5, n10, n20 = 0, 0, 0
        for b in bills:
            print(n5, n10, n20)
            match b:
                case 5:
                    n5 += 1
                case 10:
                    if n5 == 0:
                        return False
                    n5 -= 1; n10 += 1
                case 20:
                    if n10 >= 1 and n5 >= 1:
                        n5 -= 1; n10 -= 1; n20 += 1
                    elif n5 >= 3:
                        n5 -= 3; n20 += 1
                    else:
                        return False
        return True
                    
