class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();

        int low = 0;
        int high = n-1;

        int min;

        while(low!=high-1){
            int medium = (low+high)/2;

            if(nums[high]>nums[medium]){
                high = medium;
            } else{ //if less than
                low = medium;
            }
        }

        return nums[low]<nums[high] ? nums[low] : nums[high];
    }
};
