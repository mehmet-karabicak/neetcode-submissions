class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()<=1){
            return nums.size();
        } 

        map<int, int> myMap;

        for (int num: nums){
            myMap[num]++;
        }

        auto it = myMap.begin();

        int longestConsecutive = 1;
        int currentConsecutive = 1;
        int previous = it->first;
        
        ++it; //move to the second element

        for (; it != myMap.end(); ++it){
            if (it->first == previous+1){
                currentConsecutive++;
            } else{
                currentConsecutive = 1;
            }

            if (currentConsecutive>longestConsecutive){
                longestConsecutive = currentConsecutive;
            }

            previous = it->first;
        }
        return longestConsecutive;
    }
};
