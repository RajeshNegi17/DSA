class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long no_missing_sum = n*(n+1)/2;
        long long current_arr_sum = 0;
        for(int a : nums){
            current_arr_sum += a;
        } 

        int ans=0;
        ans = abs(no_missing_sum - current_arr_sum);
        return ans;
    }
};