class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int> soFar, int start, int sum, int target){
        if(start==nums.size()){
            return;
        }

        backtrack(result, nums, soFar, start+1, sum, target); //do nothing, move ahead

        sum += nums[start];
        soFar.push_back(nums[start]);

        if(sum>target) return;

        if(sum==target){
            result.push_back(soFar);
            return;
        }

        backtrack(result, nums, soFar, start, sum, target); //add the current value, and still call it

        /*backtrack(result, nums, soFar, start+1, sum, target); //add the current value, go ahead*/
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> soFar;

        backtrack(result, nums, soFar, 0, 0, target);

        return result;
    }
};
