class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j, 0});
                }
            }
        }

        int maxMin = 0;

        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();

            maxMin = max(maxMin, vec[2]);

            for (auto [dr, dc] : dirs) {
                int nr = vec[0] + dr, nc = vec[1] + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc, vec[2]+1});
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return maxMin;
    }
};
