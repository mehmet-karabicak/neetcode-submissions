class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1){
            return 0;
        }

        int lowest = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++){
            int currProfit = prices[i] - lowest;

            if(currProfit>maxProfit) maxProfit = currProfit;

            if(prices[i]<lowest) lowest = prices[i];
        }

        return maxProfit;
    }
};
