
from typing import List


class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        dir = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        def dfs(x, y):
            if not (0 <= x < rows and 0 <= y < cols and grid[x][y]):
                return 0

            element = grid[x][y]
            grid[x][y] = 0

            current_max_gold = element + max(
                dfs(x + dx, y + dy) for dx, dy in dir
            )
            
            grid[x][y] = element 

            return current_max_gold
        
        rows, cols = len(grid), len(grid[0])        
        return max(dfs(x, y) for x in range(len(grid)) for y in range(len(grid[0])))