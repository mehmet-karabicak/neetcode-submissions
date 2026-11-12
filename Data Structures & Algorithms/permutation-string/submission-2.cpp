class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        int windowSize = s1.length();

        array<int, 26> letters1 = {};

        for(char c: s1){
            letters1[(c-96)-1] += 1;
        }

        for(int i=0; i <= s2.length()-windowSize; i++){
            array<int, 26> letters2 = {};
            for(int j=i; j<i+windowSize; j++){
                letters2[(s2[j]-96)-1]+=1;
            }

            if (letters1==letters2) return true;
        }

        return false;
    }
};
