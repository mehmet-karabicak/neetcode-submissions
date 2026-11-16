class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int smallest = nums[i];
            int smallestIdx = i;

            for(int j=i; j<nums.size(); j++){
                if(nums[j]<=smallest){
                    smallest = nums[j];
                    smallestIdx = j;
                } 
            }
            if(smallestIdx!=i){
                swap(nums[i], nums[smallestIdx]);
            }
        }

        return nums;
    }
};