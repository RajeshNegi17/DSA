class Solution {
public:

    void solve(vector<vector<int>>& result,vector<int>&nums, vector<int> &curr_arr, int i){
        if( i>= nums.size()){
            result.push_back(curr_arr);
            return;
        }
        curr_arr.push_back(nums[i]);
        solve(result,nums,curr_arr,i+1);
        curr_arr.pop_back();

        solve(result,nums,curr_arr,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr_arr;
        solve(result, nums, curr_arr, 0);
        return result;
    }
};