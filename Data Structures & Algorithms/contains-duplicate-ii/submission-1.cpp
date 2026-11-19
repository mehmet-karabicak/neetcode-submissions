class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;

        unordered_map<int, vector<int>> hash;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]].push_back(i);
        }

        for(const auto& pairs: hash){
            int left = 0;
            int right = 1;

            if(pairs.second.size()==1){
                continue;
            } else{
                for(int i=1; i<pairs.second.size(); i++){
                    if(pairs.second[i]-pairs.second[i-1]<=k){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};