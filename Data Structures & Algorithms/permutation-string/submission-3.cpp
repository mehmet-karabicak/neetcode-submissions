class Solution {
public:
    bool areEqual(vector<int>& vec1, vector<int>& vec2){
        for(int i=0; i<26; i++){
            if(vec1[i]!=vec2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        int windowSize = s1.length();

        vector<int> vec1(26, 0);

        for(char c: s1){
            vec1[c-'a'] ++;
        }

        for(int i=0; i <= s2.length()-windowSize; i++){
            vector<int> vec2(26,0);

            for(int j=i; j<i+windowSize; j++){
                vec2[s2[j]-'a']++;
            }

            if(areEqual(vec1,vec2)) return true;
        }

        return false;
    }
};
