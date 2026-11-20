/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while(left<right){
            long medium = (left+right)/2;

            int guess_ = guess(medium);

            if(guess_==0){
                return medium;
            } else if(guess_==1){
                left = medium+1;
            } else{
                right = medium-1;
            }
        }

        return left;
    }
};