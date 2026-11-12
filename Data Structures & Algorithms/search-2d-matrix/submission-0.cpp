class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int colSize = matrix[0].size();
        int rowSize = matrix.size();

        int n = colSize*rowSize;

        int low = 0;
        int high = n-1;

        while(low<=high){
            int medium = (low+high)/2;

            int row = medium/colSize;
            int col = medium%colSize;

            if(matrix[row][col]>target){
                high = medium-1;
            } else if(matrix[row][col]<target){
                low = medium+1;
            } else{
                return true;
            }
        }

        return false;
    }
};
