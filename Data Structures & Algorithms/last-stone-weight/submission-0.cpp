class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(less<int>(), move(stones));

        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            if(pq.empty()) return first;

            int second = pq.top();
            pq.pop();

            pq.push(first-second);
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
