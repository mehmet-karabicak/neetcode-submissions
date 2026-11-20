class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> hash;

        for(auto trip: trips){
            for(int i=trip[1]; i<trip[2]; ++i){
                hash[i]+=trip[0];
                if(hash[i]>capacity){
                    return false;
                }
            }
        }

        return true;
    }
};