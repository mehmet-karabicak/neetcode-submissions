class Solution {
private:
    void search(vector<vector<char>>& grid, int r, int c){
        if(r<0 or r>=grid.size()) return;
        if(c<0 or c>=grid[0].size()) return;

        if(grid[r][c]=='1'){
            grid[r][c] = '2';

            search(grid, r+1, c);
            search(grid, r-1, c);

            search(grid, r, c+1);
            search(grid, r, c-1);
        } 
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nRows = grid.size();
        int nCols = grid[0].size();

        int count = 0;

        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                if(grid[i][j]=='1'){
                    search(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
