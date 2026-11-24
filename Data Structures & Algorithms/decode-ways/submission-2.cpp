class Solution {
private:
    unordered_map<int, int> myMap;

    int iterate(string& s, int idx){
        if(s[idx]=='0') return 0;
        
        if(idx>=s.length()-1) return 1;

        if(myMap.count(idx)) return myMap[idx];

        int ret_;

        if(s[idx]=='1' or (s[idx]=='2' and  s[idx+1]<='6')){
            ret_ = iterate(s, idx+1) + iterate(s, idx+2);
        } else{
            ret_ = iterate(s, idx+1);
        }

        myMap[idx] = ret_;
        
        return ret_;
    }
public:
    int numDecodings(string s) {
        return iterate(s, 0);
    }
};
