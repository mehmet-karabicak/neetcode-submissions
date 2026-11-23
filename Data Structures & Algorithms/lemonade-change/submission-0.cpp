class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> vec(3,0);

        for(int bill: bills){
            int remainder = bill - 5;

            while(remainder>=20 and vec[2]>0){
                remainder-=20;
                vec[2]--;
            }

            while(remainder>=10 and vec[1]>0){
                remainder-=10;
                vec[1]--;
            }

            while(remainder>=5 and vec[0]>0){
                remainder-=5;
                vec[0]--;
            }

            if(remainder>0){
                return false;
            } else{
                if(bill == 5) vec[0]++;
                if(bill == 10) vec[1]++;
                if(bill == 20) vec[2]++;
            }
        }

        return true;
    }
};