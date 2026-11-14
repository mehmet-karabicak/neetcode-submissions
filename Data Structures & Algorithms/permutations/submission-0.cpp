class Solution {
public:
    void backtrack(vector<vector<int>>&result, queue<int>& myQ, vector<int>& soFar){
        if(myQ.empty()){
            result.push_back(soFar);
            return;
        }

        int n = myQ.size();

        for(int i=0; i<n; i++){
            int poppedValue = myQ.front();
            myQ.pop();
            soFar.push_back(poppedValue);

            backtrack(result, myQ, soFar);
            myQ.push(poppedValue);
            soFar.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> soFar;

        queue<int> myQueue(deque<int>(nums.begin(), nums.end()));

        backtrack(result, myQueue, soFar);

        return result;
    }
};
