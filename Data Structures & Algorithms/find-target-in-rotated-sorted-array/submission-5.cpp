class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            return nums[0]==target ? 0 : -1;
        }

        int low = 0;
        int high = nums.size()-1;

        while(true){
            int medium = (low+high)/2;

            if(nums[high]==target){
                return high;
            } else if(nums[low]==target){
                return low;
            }

            if(high-low<=1){
                return -1;
            }

            if(nums[medium]==target){
                return medium;
            }else if(nums[medium]>target){
                if(nums[medium]>nums[low]){
                    if(nums[low]<target){
                        high = medium;
                    } else{
                        low = medium;
                    }
                } else{
                    high = medium;
                }
            } else{ //nums[medium]<target
                if(nums[medium]>nums[low]){
                    low = medium;
                } else{
                    if(nums[low]>target){
                        low = medium;
                    } else{
                        high = medium;
                    }
                }
            }
        }

        return -1;
    }
};
