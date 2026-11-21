class Solution {
private:
    int area(vector<vector<int>>& grid, int r, int c){
        if(r<0 or r>=grid.size()) return 0;
        if(c<0 or c>=grid[0].size()) return 0;

        if(grid[r][c]==1){
            grid[r][c] = 2;

            return 1 + area(grid, r+1, c) + area(grid, r-1, c) + area(grid, r, c+1) + area(grid, r, c-1);
        } 
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        int maxArea = 0;

        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                if(grid[i][j]==1){
                    int area_ = area(grid, i, j);
                    maxArea = max(maxArea, area_);
                }
            }
        }

        return maxArea;
    }
};

