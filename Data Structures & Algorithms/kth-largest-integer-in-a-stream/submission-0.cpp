class KthLargest {
    private:
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int kLimit;
public:

    KthLargest(int k, vector<int>& nums) {
        kLimit = k;
        for(int num: nums){
            add(num);
        }
    }
    
    int add(int val) {
       minHeap.push(val);
       if(minHeap.size() > kLimit) {
            minHeap.pop();
       } 
       return minHeap.top();
    }
};
