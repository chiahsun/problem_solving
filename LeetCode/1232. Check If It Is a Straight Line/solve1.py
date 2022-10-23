from functools import cmp_to_key
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        # https://stackoverflow.com/questions/5213033/sort-a-list-of-lists-with-a-custom-compare-function
        coordinates.sort(key=cmp_to_key(lambda p1, p2: p1[0] < p2[0]))
        dx, dy = coordinates[1][0]-coordinates[0][0], coordinates[1][1] - coordinates[0][1]
        for i in range(2, len(coordinates)):
            if dy*(coordinates[i][0]-coordinates[0][0]) != (coordinates[i][1]-coordinates[0][1])*dx:
                return False
        return True
