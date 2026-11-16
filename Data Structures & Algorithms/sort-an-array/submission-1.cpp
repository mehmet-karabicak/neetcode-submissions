class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num: nums){
            pq.push(num);
        }

        int i=0;
        while(!pq.empty()){
            nums[i] = pq.top();
            pq.pop();
            i++;
        }

        return nums;
    }
};