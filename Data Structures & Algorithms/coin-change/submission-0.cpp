class Solution {
    int dfs(const vector<int>& coins, vector<int>& memo, int soFar, int amount) {
        if (soFar == amount) return 0;
        if (memo[soFar] != -2) return memo[soFar];

        int best = INT_MAX;
        for (int coin : coins) {
            if (coin <= amount - soFar) {
                int sub = dfs(coins, memo, soFar + coin, amount);
                if (sub != -1) {
                    best = min(best, 1 + sub);
                }
            }
        }

        memo[soFar] = (best == INT_MAX) ? -1 : best;
        return memo[soFar];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // -2 = uncomputed, -1 = unreachable from this state
        vector<int> memo(amount + 1, -2);
        return dfs(coins, memo, 0, amount);
    }
};