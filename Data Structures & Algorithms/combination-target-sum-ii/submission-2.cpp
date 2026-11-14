class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& soFar, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(soFar);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same level of recursion
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // If the current candidate exceeds the remaining target, break early (since it's sorted)
            if (candidates[i] > target) break;
            
            soFar.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, soFar, result); // i + 1 because each element can be chosen at most once
            soFar.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> soFar;
        backtrack(candidates, target, 0, soFar, result);
        return result;
    }
};