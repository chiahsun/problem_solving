class Solution:
    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:

        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        return (jug1Capacity + jug2Capacity >= targetCapacity) and targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0
       
