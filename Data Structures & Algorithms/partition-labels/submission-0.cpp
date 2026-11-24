class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> answer;

        unordered_map<char, int> map;

        for(char c: s){
            map[c]++;
        }

       int n = s.length();
       int i = 0;

       int capacitySeries = 0;
       int countSeries = 0;

       while(i<n){
            capacitySeries += map[s[i]];
            map[s[i]] = 0;

            countSeries++;

            if(countSeries==capacitySeries){
                answer.push_back(countSeries);
                countSeries = 0;
                capacitySeries = 0;
            }
            i++;
       }

        return answer;
    }
};
