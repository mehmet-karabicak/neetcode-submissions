class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int i = 0;
        int n = triplets.size();

        int idx = -1;

        while(i<=n-1){
            bool possibleAdd = true;
            for(int m=0; m<3; m++){
                if(triplets[i][m]>target[m]){
                    possibleAdd = false;
                    break;
                }
            }

            if(possibleAdd){
                if(idx==-1){
                    idx = i;
                }
                else{
                    triplets[i][0] = max(triplets[i][0], triplets[idx][0]);
                    triplets[i][1] = max(triplets[i][1], triplets[idx][1]);
                    triplets[i][2] = max(triplets[i][2], triplets[idx][2]);
                    idx = i;
                }
            }

            i++;
        }

        idx = max(0, idx);

        return triplets[idx] == target;
    }
};
