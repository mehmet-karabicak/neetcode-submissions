class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totalPerimeter = 0;

        int nRow = grid.size();
        int nCol = grid[0].size();

        for(int i=0; i<nRow; i++){
            for(int j=0; j<nCol; j++){
                if(grid[i][j]==1){
                    if(i==0 or grid[i-1][j]!=1){
                        totalPerimeter++;
                    } 
                    if(i==nRow-1 or grid[i+1][j]!=1){
                        totalPerimeter++;
                    }
                    if(j==0 or grid[i][j-1]!=1){
                        totalPerimeter++;
                    } 
                    if(j==nCol-1 or grid[i][j+1]!=1){
                        totalPerimeter++;
                    }
                }
            }
        }

        return totalPerimeter;
    }
};