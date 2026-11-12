class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        //int left_product = 1;
        for (int i=1; i<nums.size(); i++){ //iterating from left to right;
            ans[i]= ans[i-1] * nums[i-1];
        }

        int right_product = 1;
        for (int i=nums.size()-1; i>=0; i--){ //from right to left
            ans[i] *= right_product;
            right_product *= nums[i];
        }

        return ans;

    }
};