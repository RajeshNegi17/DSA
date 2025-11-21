class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int left=0;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                min_len = min(min_len,right-left+1);
                sum -= nums[left]; 
                left++;
            }
        }
        if(min_len==INT_MAX){
            return 0;
        }
        return min_len;
    }
};