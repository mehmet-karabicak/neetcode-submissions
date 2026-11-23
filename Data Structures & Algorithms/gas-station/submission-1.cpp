class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1 and gas[0]>=cost[0]){
            return 0;
        }
        
        int n = gas.size();

        int visitedCount = 0;
        int idx = 0;
        int totalGas = 0;
        int i = 0;

        while(i<n*2){
            if(totalGas + gas[i%n] < cost[i%n]){
                idx = (i+1)%n;
                visitedCount = 0;
                totalGas = 0;
            } else{
                totalGas = totalGas + gas[i%n] - cost[i%n];
                visitedCount++;
            }

            if(visitedCount==n){
                return idx;
            }

            i++;
        }

        return -1;
    }
};
