class Solution {
public:

    int solve(vector<int>& nums, int i,vector<int>&memTable){
        if( i>=nums.size()){
            return 0;
        }
        if( memTable[i] != -1 ){
            return memTable[i];
        }
        int rob = nums[i] + solve(nums, i+2, memTable);
        int leave = solve(nums, i+1 , memTable);

        return memTable[i] = max(rob, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memTable(n+1,-1);
        return solve(nums,0,memTable);
    }
};