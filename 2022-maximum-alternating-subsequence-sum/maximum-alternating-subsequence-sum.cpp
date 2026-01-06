class Solution {
public:

    long long solve(int i, vector<int>&nums, int n ,long long dp[][2], bool flag){
        if( i>=n ) return 0;
        if(dp[i][flag] != -1){
            return dp[i][flag];
        }
        long long skip = solve(i+1, nums, n, dp, flag);
        long long val = nums[i];
        if(flag == false){
            val = -val;
        }
        long long take = solve(i+1, nums, n, dp , !flag) + val;

        return dp[i][flag]=max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long dp[1000001][2];
        memset(dp,-1,sizeof(dp));
        bool isEven= true;
        return solve(0,nums,n,dp,isEven);
    }
};