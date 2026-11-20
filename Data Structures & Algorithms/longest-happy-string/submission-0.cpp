class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        s.reserve(a+b+c);

        if((a+b+c)==0) return "";

        priority_queue<pair<int,int>> pq;

        if(a>0) pq.push({a, 0});
        if(b>0) pq.push({b, 1});        
        if(c>0) pq.push({c, 2});


        //if pq[0][0] > pq[1][0] by 2 or greater... then push first twice and second once.

        cout<<"pq.size()="<<pq.size()<<endl;

        while(!pq.empty()){
            auto [count1, let1] = pq.top();
            pq.pop();

            if(pq.empty()){
                for(int i=0; i<min(count1,2); i++){
                    s += let1 + 'a';
                }
                break;
            }

            auto [count2, let2] = pq.top();
            pq.pop();

            if(count1>=count2+2){
                for(int i=0; i<2; i++){
                    count1--;
                    s += let1 + 'a';
                }
                s += let2;
                count2--;
            } else{
                s += let1 + 'a';
                count1--;

                s += let2 + 'a';
                count2--;
            }

            if(count1>0){
                pq.push({count1, let1});
            }

            if(count2>0){
                pq.push({count2, let2});
            }
        }


        return s;
    }
};