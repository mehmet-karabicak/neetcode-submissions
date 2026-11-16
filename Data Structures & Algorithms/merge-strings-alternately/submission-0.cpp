class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        int shortSize = min(n1, n2);

        string s;

        for(int i=0; i<shortSize; i++){
            s+=word1[i];
            s+=word2[i];
        }

        if(n1>shortSize){
            for(int i=shortSize; i<n1; i++){
                s+=word1[i];
            }
        }

        if(n2>shortSize){
            for(int i=shortSize; i<n2; i++){
                s+=word2[i];
            }
        }

        return s;   
    }
};