class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        int row = grid.size();
        int col = grid[0].size();

        for(int i= 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    
                    perimeter += 4;
                    if(i-1 >= 0 and grid[i-1][j])
                        perimeter--;
                    if(j-1 >= 0 and grid[i][j-1])
                        perimeter --;
                    if(i+1 < row and grid[i+1][j])
                        perimeter--;
                    if(j+1 < col and grid[i][j+1])
                        perimeter --;
                }
            }
        }
        return perimeter;
    }
};