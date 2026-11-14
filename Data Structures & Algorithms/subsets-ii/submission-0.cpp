class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& soFar, int currIndex){
        result.push_back(soFar);

        for(int i=currIndex; i<nums.size(); i++){
            if (i > currIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include element and recurse
            soFar.push_back(nums[i]);
            backtrack(result, nums, soFar, i + 1);
            soFar.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> soFar;

        //first I need to sort the vector nums
        sort(nums.begin(), nums.end());

        backtrack(result, nums, soFar, 0);

        return result;
    }
};
