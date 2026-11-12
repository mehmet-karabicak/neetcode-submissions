class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];

        for(int pile: piles){
            if(pile>max) max = pile;
        }

        int lowestPossible = max;
        int largestImpossible = 0;

        while(largestImpossible<lowestPossible-1){
            int medium = (largestImpossible+lowestPossible)/2;

            long long totalHours = 0;

            for(int pile: piles){
                if(pile<=medium){
                    totalHours+=1;
                } else if(pile%medium==0){
                    totalHours += (pile/medium);
                } else{
                    totalHours += (pile/medium)+1;
                }
            }

            if(totalHours<=h){
                lowestPossible = medium;
            } else{
                largestImpossible = medium;
            }
        }

        return lowestPossible;
    }
};
