class Solution {
public:
    int mySqrt(int x) {
        long left = 0, right = x;

        while(left<right){
            long medium = (left+right+1)/2;

            if(medium*medium==x){
                return medium;
            } else if(medium*medium>x){
                right = medium - 1;
            } else{
                left = medium + 1;
            }
        }

        return left*left>x ? left-1 : left;
    }
};