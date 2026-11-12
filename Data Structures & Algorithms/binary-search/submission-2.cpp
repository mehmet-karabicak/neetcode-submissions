class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        int medium;

        while(low<high){
            medium = (low+high)/2;

            cout<<"nums[medium]: "<<nums[medium]<<endl;

            if(nums[medium]>target){
                high = medium-1;
            } else if(nums[medium]<target){
                low = medium+1;
            } else{
                return medium;
            }

            cout<<"low: "<<low<<" high: "<<high<<endl;
        }

        if(low==high and nums[low]==target){
            return low;
        }

        return -1;
    }
};
