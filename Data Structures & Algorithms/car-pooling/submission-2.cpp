class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), []
        (vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        int currPass = 0;

        int n = trips[trips.size()-1][2];

        for(auto trip: trips){
            currPass += trip[0];
            q.push({trip[2], trip[0]});

            int i = trip[1];

            while(q.top().first <= i){
                currPass-=q.top().second;
                q.pop();
            }

            if(currPass>capacity){
                return false;
            }
        }

        return true;
    }
};