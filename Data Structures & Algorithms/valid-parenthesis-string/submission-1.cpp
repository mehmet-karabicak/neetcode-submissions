class Solution {
public:
    bool checkValidString(string s) {
        int i = 0;
        int n = s.length();

        stack<char> openSt, starSt;

        while(i<n){
            if(s[i]=='('){
                openSt.push(i);
            } else if(s[i]=='*'){
                starSt.push(i);
            } else{
                if(!openSt.empty()){
                    openSt.pop();
                } else if(!starSt.empty()){
                    starSt.pop();
                } else{
                    return false;
                }
            }
            
            i++;
        }

        while(!openSt.empty() and !starSt.empty()){
            if(openSt.top()>starSt.top()) return false;
            openSt.pop();
            starSt.pop();
        }



        return openSt.empty();
    }
};
