class Solution {
public:
    string reorganizeString(string s) {
        vector<int> vec(26,0);

        for(char c: s){
            vec[c-'a']++;
        }

        string ans;

        priority_queue<pair<int,int>> pq;

        for(int i=0; i<26; i++){
            if(vec[i]>0){
                pq.push({vec[i],i});
            }
        }

        while(!pq.empty()){
            auto [count1, let1] = pq.top();
            pq.pop();

            ans += let1 + 'a';

            if(pq.empty()){
                if(count1>1) return "";
                break;
            }

            auto [count2, let2] = pq.top();
            pq.pop();

            ans += let2 + 'a';

            count1--;
            count2--;

            if(count1>0){
                pq.push({count1, let1});
            }
            
            if(count2>0){
                pq.push({count2, let2});
            }
        }

        return ans;
    }
};