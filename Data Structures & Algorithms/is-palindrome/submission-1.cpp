class Solution {
public:
    bool isPalindrome(string s) {
        string fromStart = "";
        string fromEnd = "";

        for (int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                fromStart+=tolower(s[i]);
            }

            if(isalnum(s[s.size()-1-i])){
                fromEnd+=tolower(s[s.size()-1-i]);
            }
        }

        cout<<"String from start: "<<fromStart;
        cout<<" String from end: "<<fromEnd<<endl;

        if (fromStart.size()!=fromEnd.size()){
            return false;
        }

        for (int i=0; i<fromStart.size(); i++){
            if (fromStart[i]!=fromEnd[i]){
                return false;
            }
        }

        return true;
    }
};
