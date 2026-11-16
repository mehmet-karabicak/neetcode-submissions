class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> vec(3,0);

        for(int i=0; i<nums.size(); i++){
            vec[nums[i]]++;
        }

        for(int i=0; i<vec[0]; i++){
            nums[i] = 0;
        }

        for(int i=vec[0]; i<vec[0]+vec[1]; i++){
            nums[i] = 1;
        }

        for(int i=vec[0]+vec[1]; i<vec[0]+vec[1]+vec[2]; i++){
            nums[i] = 2;
        }
    }
};   