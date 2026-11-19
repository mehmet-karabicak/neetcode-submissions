class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;

        unordered_map<int,int> hash;

        int i=0;

        while(i<nums.size()){
            if(hash.contains(nums[i])){
                if(abs(i-hash[nums[i]])<=k){
                    return true;
                }
            }

            hash[nums[i]] = i;

            i++;
        }

        return false;
    }
};