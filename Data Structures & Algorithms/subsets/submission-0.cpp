class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& temp, int start){
        if (start==nums.size()){
            result.push_back(temp);
            return;
        }

        while(start<nums.size()){
            temp.push_back(nums[start]);

            ++start;

            backtrack(nums, temp, start);

            temp.pop_back();
        }

        result.push_back(temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();

        vector<int> temp;

        backtrack(nums, temp, 0);

        return result;
    }
};