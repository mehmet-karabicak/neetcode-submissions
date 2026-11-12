class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        vector<vector<int>> result;

        vector<int> final_result;

        for (auto num: nums){
            num_map[num]++;
        }
        for (const auto& [key, val]: num_map){
            result.push_back({key, val});
        }

        int i = 1;

        sort(result.begin(), result.end(), [i](const vector<int>& a,
        const vector<int>& b){
            return a[i] > b[i];
        });

        for (int i=0; i<k; i++){
            final_result.push_back(result[i][0]);
        }

        return final_result;
    }
};
