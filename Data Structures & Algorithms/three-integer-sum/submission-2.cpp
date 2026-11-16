class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        if(nums[n-1]<0) return {};
        if(nums[n-1]==0 and nums[0]<0) return {};
        if(nums[n-1]==0 and nums[0]==0) return {{0,0,0}};

        int i=0;

        while(i<(n-2)){
            if(nums[i]>0) break;

            int left = i+1;
            int right = n-1;

            while(right>left){
                int total = (nums[i] + nums[right] + nums[left]);

                if(total==0){
                    answer.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(nums[right]==nums[right-1]){
                        right--;
                    }

                    left++;
                    right--;
                } else if(total<0){
                    left++;
                } else{
                    right--;
                }
            }

            while (i < n - 2 && nums[i] == nums[i + 1]) {
                i++;
            }

            i++;
        }

        return answer;
    }
};

//1:05:39
