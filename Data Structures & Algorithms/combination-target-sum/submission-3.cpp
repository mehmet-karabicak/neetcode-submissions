class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& soFar, int start, int sum, int target){
        if(sum==target){
            result.push_back(soFar);
            return;
        }

        if(start==nums.size() or sum>target){
            return;
        }

        sum += nums[start];
        soFar.push_back(nums[start]);

        backtrack(result, nums, soFar, start, sum, target); //add the current value, and still call it

        sum -= nums[start];
        soFar.pop_back();

        backtrack(result, nums, soFar, start+1, sum, target); //do nothing, move ahead

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> soFar;

        backtrack(result, nums, soFar, 0, 0, target);

        return result;
    }
};
