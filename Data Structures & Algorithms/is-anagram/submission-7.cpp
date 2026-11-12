
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        } 

        unordered_map<char, int> hash_s, hash_t;

        for (int i=0; i<t.size(); i++){
            hash_s[s[i]] += 1;
            hash_t[t[i]] += 1;
        }

        if (hash_s.size()!=hash_t.size()){
            return false;
        }

        for (const auto& [key, value]: hash_s){
            if (value!=hash_t[key]){
                return false;
            }
        }
        return true;
    }
};
