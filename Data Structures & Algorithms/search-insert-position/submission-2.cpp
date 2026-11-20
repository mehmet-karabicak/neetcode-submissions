class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0]) {
            return 0;
        }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        if(target==nums[nums.size()-1]){
            return nums.size()-1;
        }

        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int medium = (left+right+1)/2;

            if(nums[medium]==target){
                return medium;
            }
            else if(nums[medium]>target){
                right = medium-1;
            }
            else{
                left = medium+1;
            }
        }

        if(nums[left]<target and nums[left+1]>target){
            return left+1;
        }
        if(nums[left]>target and nums[left-1]>target){
            return left-1;
        }
        return left;
    }
};