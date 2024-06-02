int max(int x, int y){
    return (x > y)? x : y;
}

int search(int**grid, int i, int j, int gridSize, int* gridColSize){
    int element = grid[i][j];
    int current_gold = 0;
    int x, y;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    current_gold+=element;
    grid[i][j] = 0;
    
    if (element != 0){

        for (int dir=0; dir<4; dir++){
            x = i+dx[dir];
            y = j+dy[dir];

            if (x >= 0 && x < gridSize && y >= 0 && y < gridColSize[i] && grid[x][y]!= 0){
                 current_gold += search(grid, x, y, gridSize, gridColSize);
            }
        }   
    }
    
    grid[i][j] = element;
    
    return current_gold;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
    int max_gold = 0;
    
    for (int i; i < gridSize; i++){
        for (int j; j < gridColSize[i]; j++){
            if(grid[i][j] != 0){
                max_gold = max(max_gold, search(grid, i, j, gridSize, gridColSize[i]));
            }
        }
    }
    return max_gold;
}
