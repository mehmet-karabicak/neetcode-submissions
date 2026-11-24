class Solution {
private:
    int dfs(vector<int>& nums, vector<int>& memo, int idx){
        if(idx>=nums.size()) return 0;
        if(memo[idx]!=-1) return memo[idx];

        int ret_ = max(nums[idx]+dfs(nums, memo, idx+2), dfs(nums, memo, idx+1));

        memo[idx] = ret_;

        return ret_;
    }
public:

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dfs(nums, memo, 0);
    }
};
