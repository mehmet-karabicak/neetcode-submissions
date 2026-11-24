class Solution {

public:

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();

        int oneStep1 = 0;
        int twoStep1 = 0;

        for(int i=n-2; i>=0; --i){
            int current = max(nums[i]+twoStep1, oneStep1);
            twoStep1 = oneStep1;
            oneStep1 = current;
        }

        int oneStep2 = 0;
        int twoStep2 = 0;

        for(int i=n-1; i>=1; --i){
            int current = max(nums[i]+twoStep2, oneStep2);
            twoStep2 = oneStep2;
            oneStep2 = current;
        }

        return max(oneStep1, oneStep2);
    }
};