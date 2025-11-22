class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>> result;
        for(string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        for(auto &value : map){
            result.push_back(value.second);
        }
        return result;
    }
};