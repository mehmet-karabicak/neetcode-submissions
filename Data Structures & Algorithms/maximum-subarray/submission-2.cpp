class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//in-place replacement?
        if(nums.size()==1){
            return nums[0];
        }
        int maxTotal = INT_MIN;
        int runninTotal = 0;

        for(int num: nums){
            runninTotal += num;

            if(runninTotal>maxTotal) maxTotal = runninTotal;
            
            if(runninTotal<0) runninTotal = 0;
        }

        return maxTotal;
    }
};
