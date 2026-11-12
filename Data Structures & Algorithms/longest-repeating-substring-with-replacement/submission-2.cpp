class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()<=1){
            return s.length();
        }

        int maxLength = 0;
        int startIndex = 0;
        int maxFreq = 0;
        unordered_map<char, int> freqMap;

        for(int endIdx=0; endIdx<s.length(); endIdx++){     
            freqMap[s[endIdx]]++;
            maxFreq = max(maxFreq, freqMap[s[endIdx]]);

            while((endIdx - startIndex + 1) - maxFreq > k){
                freqMap[s[startIndex]]--;

                startIndex++;
            }

            maxLength = max(maxLength, endIdx - startIndex + 1);
        }

        return maxLength;
    }
};
