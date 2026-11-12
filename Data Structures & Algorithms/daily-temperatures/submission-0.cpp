class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);

        stack<int> myStack;

        for(int i=0; i<size; i++){
            int count = 0;

            while(!myStack.empty() and temperatures[i]>temperatures[myStack.top()]){
                result[myStack.top()] = i-myStack.top();
                myStack.pop();
            }

            myStack.push(i);
        }

        return result;
    }
};
