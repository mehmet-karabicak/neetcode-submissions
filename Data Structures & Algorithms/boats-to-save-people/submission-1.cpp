class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), []
        (int a, int b){
            return a>b;
        });

        int boats = 0;

        int right = people.size()-1;
        int left = 0;

        while(left<=right){
            if(left==right){
                boats++;
                break;
            }
            if(people[left]+people[right]<=limit){
                right--;
            }
            left++;
            boats++;
        }

        return boats;
    }
};