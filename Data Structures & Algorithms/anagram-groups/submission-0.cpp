class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for (int i=0; i<strs.size(); i++){
            string key = strs[i];
            
            sort(key.begin(), key.end());

            anagramGroups[key].push_back(strs[i]);
        }
        vector<vector<string>> answer;

        for(const auto& [key, anagramGroup] : anagramGroups)
        {
            answer.push_back(anagramGroup);
        }

        return answer;
    }
};