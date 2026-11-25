#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int val = nums[i];
            int cand1 = val;
            int cand2 = currMax * val;
            int cand3 = currMin * val;

            currMax = max({cand1, cand2, cand3});
            currMin = min({cand1, cand2, cand3});
            ans = max(ans, currMax);
        }

        return ans;
    }
};