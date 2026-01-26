class Solution {
public:
    void solve(vector<string>& strs, vector<vector<string>>&result) {
        unordered_map<string,vector<string>> map;
        for( string str : strs ){
            string temp = str;
            sort(temp.begin(),temp.end());
            map[temp].push_back(str);
        }

        for( auto &ans : map ){
            result.push_back(ans.second);
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        solve(strs,result);
        return result;
    }
};