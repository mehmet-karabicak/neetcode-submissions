class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        int windowSize = s1.length();

        unordered_map<char, int> hash1;

        for(char c: s1){
            hash1[c]++;
        }

        for(int i=0; i <= s2.length()-windowSize; i++){
            unordered_map<char, int> hash2;
            for(int j=i; j<i+windowSize; j++){
                hash2[s2[j]]++;
            }

            bool matches = true;

            for(const auto& pair: hash2){
                if (hash1[pair.first]!=pair.second){
                    matches = false;
                }
            }

            if (matches==true){
                return true;
            }
        }

        return false;
    }
};

