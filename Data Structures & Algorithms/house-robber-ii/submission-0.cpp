class Solution {
private:
    int dfs(vector<int>& nums, vector<int>& memo, bool visitedOne, int idx){
        if(visitedOne){
            if(idx>=nums.size()-1) return 0;
        } else{
            if(idx>=nums.size()) return 0;
        }

        if(memo[idx]!=-1) return memo[idx];

        int ret_ = max(nums[idx]+dfs(nums, memo, visitedOne, idx+2), dfs(nums, memo, visitedOne, idx+1));

        memo[idx] = ret_;

        return ret_;
    }
public:

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);

        return max(nums[0] + dfs(nums, memo, true, 2), dfs(nums, memo2, false, 1));
    }
};