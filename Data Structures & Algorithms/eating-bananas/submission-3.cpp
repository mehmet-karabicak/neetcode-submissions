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

            cout<<"Medium is: "<<medium<<"\n";

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

            cout<<"Total hours: "<<totalHours<<"\n";

            if(totalHours<=h){
                lowestPossible = medium;
            } else{
                largestImpossible = medium;
            }

            cout<<"Lowest possible: "<<lowestPossible<<"\n";
            cout<<"Largest impossible: "<<largestImpossible<<"\n"<<endl;

        }

        return lowestPossible;
    }
};
