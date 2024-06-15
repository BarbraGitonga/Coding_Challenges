# 1219. Path with Maximum Gold

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

- Every time you are located in a cell you will collect all the gold in that cell.
- From your position, you can walk one step to the left, right, up, or down.
- You can't visit the same cell more than once.
- Never visit a cell with 0 gold.
- You can start and stop collecting gold from any position in the grid that has some gold.

[Path with Maximum Gold]('https://leetcode.com/problems/path-with-maximum-gold/')

## Pseudocode

```
1. Create a helper function to carry out depth first search algorithm.
2. DFS:
    IF grid cordinate is out of bounds:
        RETURN 0
    Store value of grid and assign the grid 0 to mark it as visited
    ADD the value of grid to its highest neighbouring element in the four directions and store its value while recursively carrying out dfs on every grid.
    Restore the value of the element of the grid.
3. Iterate over all grids recursively carrying out dfs while storing the maximum value

```

