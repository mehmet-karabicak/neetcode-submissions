class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        int medium = (low+high)/2;

        while(low<high){
            if(nums[medium]>target){
                high = medium-1;
            } else if(nums[medium]<target){
                low = medium+1;
            } else{
                return medium;
            }

            medium = (low+high)/2;
        }

        if(nums[medium]==target){
            return medium;
        }

        return -1;
    }
};
