class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int l = 0;
        int r = nums[l];
        int jumpCount = 0;

        while (r < nums.size() - 1) {
            int maxReach = -1;
            int idx = -1;
            int i = l + 1;

            while (i <= r) {
                if (nums[i] + i >= maxReach) {
                    maxReach = nums[i] + i;
                    idx = i;
                }
                i++;
            }

            jumpCount++;
            l = idx;
            r = maxReach;
        }

        return jumpCount + 1;
    }
};