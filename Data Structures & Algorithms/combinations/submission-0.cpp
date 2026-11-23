class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& soFar, int idx, int n, int k){
        if(soFar.size()==k){
            ans.push_back(soFar);
            return;
        }
        
        if(idx>n){
            return;
        }

        for(int i=idx; i<=n; i++){
            soFar.push_back(i);
            backtrack(ans, soFar, i+1, n, k);
            soFar.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> soFar;

        backtrack(ans, soFar, 1, n, k);

        return ans;
    }
};