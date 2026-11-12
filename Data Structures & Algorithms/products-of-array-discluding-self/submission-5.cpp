class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size()==2){
            return {nums[1], nums[0]};
        }

        int total_product = 1;
        int total_non_zeros = 0;

        int zero_count = 0;

        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0){
                zero_count++;
            } else{
                total_non_zeros++;
                total_product *= nums[i];
            }
        }

        vector<int> ans;

        if (total_non_zeros<2 or zero_count>1){
            for (int i=0; i<nums.size(); i++){
                ans.push_back(0);
            }
        } else {
            for (int i=0; i<nums.size(); i++){
                if (zero_count==1){
                    if (nums[i]==0){
                        ans.push_back(total_product);
                    } else {
                        ans.push_back(0);
                    }
                } else {
                    ans.push_back((total_product)/nums[i]);
                }
            }
        }
        return ans;
    }
};
