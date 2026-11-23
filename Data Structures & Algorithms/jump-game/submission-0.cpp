class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>maxJump) maxJump = nums[i];

            if(maxJump==0) return false;

            maxJump--;
        }

        return true;
    }
};
