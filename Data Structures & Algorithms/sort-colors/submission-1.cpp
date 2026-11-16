class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> vec(3,0);

        for(int i=0; i<nums.size(); i++){
            vec[nums[i]]++;
        }

        for(int i=0; i<nums.size(); i++){
            if(vec[0]>0){
                nums[i] = 0;
                vec[0]--;
            } else if(vec[1]>0){
                nums[i] = 1;
                vec[1]--;
            } else{
                nums[i] = 2;
            }
        }
    }
};   