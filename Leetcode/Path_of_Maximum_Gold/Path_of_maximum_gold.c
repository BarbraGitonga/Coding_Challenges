/**
 * @brief Compare and get maximum variable
 * 
 * @param x - old integer
 * @param y - new integer
 * @return int 
 */
int max(int x, int y){
    return (x > y)? x : y;
}


 /**
  * @brief Perform a DFS from a cell
  * 
  * @param grid 
  * @param i - x starting point
  * @param j - y starting point
  * @param gridSize - number of rows 
  * @param gridColSize number of column for each row
  * @return int 
  */
int search(int** grid, int i, int j, int gridSize, int gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] <= 0) {
        return 0; // Return 0 if out of bounds or cell has no gold
    }

    int element = grid[i][j]; // Save the value stored in the cell
    grid[i][j] = 0; // Change value of cell to 0 so it's not revisited

    int dx[] = {-1, 1, 0, 0}; // x coordinates
    int dy[] = {0, 0, -1, 1}; // y coordinates
    int max_gold_from_adjacent_cells = 0;

    for (int dir = 0; dir < 4; dir++) { // Iterate in all directions
        int x = i + dx[dir]; // Move to next cell
        int y = j + dy[dir];
        //maximum gold from each cell
        max_gold_from_adjacent_cells = max(max_gold_from_adjacent_cells, search(grid, x, y, gridSize, gridColSize));
    }

    grid[i][j] = element; // Restore original value of the grid
    return element + max_gold_from_adjacent_cells; // Return the sum of the current cell's gold and the maximum gold from adjacent cells
}


/**
 * @brief Get the Maximum Gold object
 * 
 * @param grid - 2d dimensional array
 * @param gridSize - number of rows
 * @param gridColSize - number of coulumns for each row.
 * @return int 
 */
int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int max_gold = 0;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridColSize[i]; j++){
            int col = gridColSize[i];
            if(grid[i][j] != 0){
                max_gold = max(max_gold, search(grid, i, j, gridSize, col));
            }
        }
    }
    return max_gold;
}