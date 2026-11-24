class Solution {
private:
    int iterate(string& s, vector<int>& memo, int idx){
        if(s[idx]=='0') return 0;
        
        if(idx>=s.length()-1) return 1;

        if(memo[idx]!=-1) return memo[idx];

        int ret_;

        if(s[idx]=='1' or (s[idx]=='2' and  s[idx+1]<='6')){
            ret_ = iterate(s, memo, idx+1) + iterate(s, memo, idx+2);
        } else{
            ret_ = iterate(s, memo, idx+1);
        }

        memo[idx] = ret_;
        
        return ret_;
    }
public:
    int numDecodings(string s) {
        vector<int> memo(s.length()+1, -1);
        return iterate(s, memo, 0);
    }
};
