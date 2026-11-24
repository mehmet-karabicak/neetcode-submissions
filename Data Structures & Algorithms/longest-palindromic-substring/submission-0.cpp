class Solution {
private:
    void expand(const string&s, int left, int right, int& lCount, int& lLeft){
        while(left>=0 && right<(int)s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        int count = right-left-1; //right-1 - (left+1) +1;

        if(count>lCount){
            lCount = count;
            lLeft = left+1;
        }
    }
public:
    string longestPalindrome(string s) {
        int lCount = 0;
        int lLeft = 0;
        int n = (int)s.size();

        for(int i=0; i<n; ++i){
            expand(s, i, i, lCount, lLeft);
            expand(s, i, i+1, lCount, lLeft);
        }
        return s.substr(lLeft, lCount);
    }
};