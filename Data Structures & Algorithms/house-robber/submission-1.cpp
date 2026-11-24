class Solution {
private:
    unordered_map<int, int> myMap;

    int dfs(vector<int>& nums, int idx){
        if(myMap.count(idx)) return myMap[idx];
        if(idx>=nums.size()) return 0;

        int ret_ = max(nums[idx]+dfs(nums, idx+2), dfs(nums, idx+1));

        myMap[idx] = ret_;

        return ret_;
    }
public:
    //what is the maxiumum amount a robber could rob
    //recursion?
    int rob(vector<int>& nums) {

        return dfs(nums, 0);
    }
};
