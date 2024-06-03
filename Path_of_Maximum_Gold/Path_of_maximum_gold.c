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
int search(int**grid, int i, int j, int gridSize, int* gridColSize){
    int element = grid[i][j]; //saving the value stored in the cell
    int current_gold = 0; //initializing current_gold to 0
    int x, y; 
    int dx[] = {-1,1,0,0}; // x coordinates
    int dy[] = {0,0,-1,1}; // y coordinates

    current_gold+=element; // add elements to current gold and save the current gold from starting point cell
    grid[i][j] = 0; // change value of cell to 0 so its not revisited
    
    for (int dir=0; dir<4; dir++){ //iterate in all directions
        x = i+dx[dir]; // move to next cell
        y = j+dy[dir];

        if (x >= 0 && x < gridSize && y >= 0 && y < gridColSize && grid[x][y]!= 0) {// ensure within bounds and cell value is not 0
            current_gold += search(grid, x, y, gridSize, gridColSize);  // add values of element on each cell to the current gold
        }
    }
    grid[i][j] = element; // restoring original value of the grid
    return current_gold;
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
            if(grid[i][j] != 0){
                max_gold = max(max_gold, search(grid, i, j, gridSize, gridColSize[i]));
            }
        }
    }
    return max_gold;
}