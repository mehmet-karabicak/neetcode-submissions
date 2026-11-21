class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> vec(26);

        for(int i=0; i<26; i++){
            vec[order[i]-'a'] = i;
        }

        int i = 0;
        int n = words.size()-1;

        while(i<n){
            int m = 0;
            int lowLimit = min(words[i].size(), words[i+1].size());

            for(; m<lowLimit; ++m){
                if(vec[words[i][m]-'a']<vec[words[i+1][m]-'a']){
                    break;
                }
                if(vec[words[i][m]-'a']>vec[words[i+1][m]-'a']){
                    return false;
                }
            }

            if(m==lowLimit){
                if(words[i].size()>words[i+1].size()){
                    return false;
                }
            }

            i++;
        }

        return true;
    }
};