class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> myHash;
        int temp;
        while (true){
            temp = 0;

            while(n!=0){
                temp += (n%10) * (n%10);
                n /= 10;
            }

            if (myHash[temp]==1){
                return false;
            } else if (temp==1){
                return true;
            } else{
                myHash[temp]++;
                n=temp;
            }
        }
    }
};