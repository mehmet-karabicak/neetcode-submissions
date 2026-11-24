class Solution {
public:
    int rob(vector<int>& cost) {
        int twoStep = 0; // cost from i + 2 to top
        int oneStep = 0;  // cost from i + 1 to top

        for (int i = cost.size() - 1; i >= 0; i--) {
            int current = max(cost[i] + twoStep, oneStep);
            twoStep = oneStep;
            oneStep = current;
        }

        // You can start at index 0 or index 1
        return oneStep;
    }
};