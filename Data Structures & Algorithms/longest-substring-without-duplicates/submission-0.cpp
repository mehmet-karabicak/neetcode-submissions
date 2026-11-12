class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1){
            return s.length();
        }

        int maxLength = 0;
        int startIndex = 0;
        unordered_map<char, int> myMap;

        myMap[s[startIndex]]++;

        for(int i=1; i<s.length(); i++){
            while(myMap[s[i]]>0){
                myMap[s[startIndex]]--;

                startIndex++;
            }
            myMap[s[i]]++; //becomes 1;

            maxLength = max(maxLength, (i-startIndex)+1);
        }

        return maxLength;
    }
};
