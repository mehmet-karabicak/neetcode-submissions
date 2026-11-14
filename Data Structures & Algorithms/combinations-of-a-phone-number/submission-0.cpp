class Solution {
public:
    vector<string> digitToLetter(vector<string>& vec, vector<string> letters, int num){
        int possLettCount = letters.size(); //3
        int oneSeries = num/possLettCount;  //1

        int count = 0;
        int j=0;

        while(j<vec.size()){
            for (int m=0; m<possLettCount; m++){
                while(j<(num*count+oneSeries*(m+1))){
                    vec[j]+=letters[m];
                    j++;
                }
            }

            count++;
        }

        return vec;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        
        int totalCombinations = 1;
        vector<vector<string>> lets = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"},
                                       {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"},
                                       {"t", "u", "v"}, {"w", "x", "y", "z"}};
    
        for(char c: digits){
            int letsIndex = (c-'0')-2;

            totalCombinations *= lets[letsIndex].size();
        }

        vector<string> answer(totalCombinations);

        for(char c: digits){
            int letsIndex = (c-'0')-2;

            digitToLetter(answer, lets[letsIndex], totalCombinations);

            totalCombinations /= lets[letsIndex].size();
        }

        return answer;
    }   
};