#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicate_check;
        for (int i=0; i<nums.size(); i++){
            duplicate_check[nums[i]] += 1;
            if (duplicate_check[nums[i]]==2){
                return true;
            }
        }

        return false;
    }
};