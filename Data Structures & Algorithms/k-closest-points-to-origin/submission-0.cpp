class Solution {
public:
    struct compareAbs{
        bool operator()(const vector<int>& a, const vector<int>& b){
            size_t aDistance = a[0]*a[0] + a[1]*a[1];
            size_t bDistance = b[0]*b[0] + b[1]*b[1];

            return aDistance<bDistance;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compareAbs> pq;

        for(int i=0; i<points.size(); i++){
            pq.push(points[i]);

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> result;

        int size = pq.size();

        for(int i=0; i<size; i++){
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};
