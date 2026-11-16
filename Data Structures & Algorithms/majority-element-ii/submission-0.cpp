class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int thresh = nums.size()/3;

        unordered_map<int, int> hash;

        vector<int> result;

        for(int num: nums){
            if(hash[num]==thresh){
                result.push_back(num);
            } 
            hash[num]++;
        }

        return result;
    }
};