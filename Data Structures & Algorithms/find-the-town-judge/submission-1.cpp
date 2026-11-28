class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vec(n+1, 1);

        for(auto t: trust){
            vec[t[0]] = abs(vec[t[0]])*-1;
            vec[t[1]]++;
        }

        cout<<"how it looks: ";
        for(int v: vec){
            cout<<v<<",";
        }

        for(int i=0; i<vec.size(); i++){
            if(vec[i]==n) return i;
        }

        return -1;
    }
};