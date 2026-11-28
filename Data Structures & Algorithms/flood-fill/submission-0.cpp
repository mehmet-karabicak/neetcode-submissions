class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;

        int origColor = image[sr][sc];

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            auto [r, c] = q.front();

            q.pop();

            if(!(r<0 or r>=image.size() or c<0 or c>=image[0].size()) and image[r][c]==origColor){
                image[r][c] = color;
                q.push({r+1,c});
                q.push({r-1,c});
                q.push({r,c+1});
                q.push({r,c-1});
            } 
        }

        return image;
    }
};