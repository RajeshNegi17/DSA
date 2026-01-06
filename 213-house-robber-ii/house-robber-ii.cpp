class Solution {
public:

    int solve(vector<int>&nums , int i, vector<int>&memTable, int n){
        if(i>n) return 0;
        
        if(memTable[i] !=-1 ){
            return memTable[i];
        }

        int steal = nums[i] + solve(nums,i+2,memTable,n);
        int skip = solve(nums,i+1,memTable,n);

        return memTable[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> memTable(n+1,-1);
        int case1 = solve(nums,0,memTable,n-2); //from 0th house to second last house;
        vector<int> memTable2(n+1,-1);
        int case2 = solve(nums,1,memTable2,n-1); //skipping 0 to last house;

        return max(case1,case2);
    }
};