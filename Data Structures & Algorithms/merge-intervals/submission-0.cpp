class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), []
        (const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            } else{
                return a[0]<b[0];
            }
        });
        
        size_t i=0, n=intervals.size();

        while(i<n){
            size_t j=i+1;

            while(j<n && intervals[j][0]<=intervals[i][1]){
                intervals[i][0] = min(intervals[j][0], intervals[i][0]);
                intervals[i][1] = max(intervals[j][1], intervals[i][1]);
                j++;
            }
            
            result.push_back(intervals[i]);
            i=j;
        }

        return result;
    }
};
