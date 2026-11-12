
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Hash(nums.begin(), nums.end());
        int best = 0;

        for (int x : Hash) {
            if (!Hash.count(x - 1)) {
                int y = x + 1;

                while (Hash.count(y)) {
                    y++;
                }

                best = max(best, y - x);
            }
        }

        return best;
    }
};
