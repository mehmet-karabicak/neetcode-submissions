class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_map;
        vector<pair<int,int>> arr;

        vector<int> result;

        for (auto num: nums){
            num_map[num]++;
        }
        for (const auto& [key, val]: num_map){
            arr.push_back({val, key});
        }

        int i = 1;

        sort(arr.rbegin(), arr.rend());

        for (int i=0; i<k; i++){
            result.push_back(arr[i].second);
        }

        return result;
    }
};
