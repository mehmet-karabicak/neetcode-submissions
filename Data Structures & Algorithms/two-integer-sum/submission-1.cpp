class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            int remainder = target - nums[i];
            for (int j=i+1; j<nums.size(); j++){
                if (nums[j]==remainder){
                    return {i, j};
                }
            }
        }
    }
};
