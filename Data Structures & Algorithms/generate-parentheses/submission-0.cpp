class Solution {
public:
    void backtrack(vector<string>& result, string soFar, int open, int closed, int n){
        if(soFar.length() == 2*n){
            result.push_back(soFar);
            return;
        }
        if(open<n){
            backtrack(result, soFar+"(", open+1, closed, n);
        }

        if(open>closed){
            backtrack(result, soFar+")", open, closed+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int open = 0;
        int closed = 0;

        backtrack(result, "", open, closed, n);

        return result;
    }
};
