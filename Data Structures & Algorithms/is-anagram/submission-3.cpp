#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        } //bu kisim dogru

        unordered_map<int, int> hash_1;
        unordered_map<int, int> hash_2;

        for (int i=0; i<t.size(); i++){
            hash_1[s[i]] += 1;
            hash_2[t[i]] += 1;
        }

        if (hash_1.size()!=hash_2.size()){
            return false;
        }

        for (const auto& [key, value]: hash_1){
            cout<<"Key is: "<<key<<"Value is: "<<value;
            if (value!=hash_2[key]){
                return false;
            }
        }
        return true;
    }

};
