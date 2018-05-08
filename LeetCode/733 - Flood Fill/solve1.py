class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        nrow, ncol = len(image), len(image[0])
        
        def dfs(row, col, newColor):
            oldColor = image[row][col]
            if oldColor == newColor:
                return
            image[row][col] = newColor
            for dx, dy in zip([1, -1, 0, 0], [0, 0, 1, -1]):
                x = row + dx
                y = col + dy
                if 0 <= x < nrow and 0 <= y < ncol and image[x][y] == oldColor:
                    dfs(x, y, newColor)
                    
        dfs(sr, sc, newColor)
        return image
        
