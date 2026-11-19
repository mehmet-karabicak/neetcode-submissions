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

            if(people[left]==limit){
                left++;
                boats++;
            }else if(people[left]+people[right]>limit){
                left++;
                boats++;
            } else{
                left++;
                right--;
                boats++;
            }
        }

        return boats;
    }
};