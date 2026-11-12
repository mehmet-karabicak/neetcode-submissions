class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lI = 0;
        int rI = numbers.size()-1;
        //int maxR = numbers.size();

        while(rI>lI){
            int total = numbers[lI]+numbers[rI];
            if (total>target){
                rI--;
            } else if(total<target){
                lI++;
            } else{
                break;
            }
        }

        /*for (int i=1; i<numbers.size(); i++){
            rI = i;
            while(rI<maxR){
                int total = numbers[lI] + numbers[rI];
                //cout<<"TOtal is: "<<total<<endl;

                if (total==target){
                    return {lI+1, rI+1};
                }

                if (total>target){
                    maxR = rI;
                    break;
                }
                rI++;
            }
            lI++;
        }*/
        //cout<<"Arrived here";
        return {lI+1,rI+1};
    }
};
