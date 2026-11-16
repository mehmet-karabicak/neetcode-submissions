class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while(left<=right){
            while(left < s.length() && !isalnum(s[left])){
                left++;
            }

            while(right > 0 && !isalnum(s[right])){
                right--;
            }

            if(left>right){
                break;           
            }

            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int n = s.length();

        int left = 0;
        int right = n-1;

        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            } else{
                return isPalindrome(s, left+1, right) or isPalindrome(s, left, right-1);
            }
        }

        return true;
    }
};