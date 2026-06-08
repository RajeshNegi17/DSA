class Solution {
    public int maxSubArray(int[] nums) {
        int max_sum=nums[0];
        int curr_sum=0;
        int n = nums.length;
        for( int i=0; i<n; i++){
            curr_sum += nums[i];
            max_sum = Math.max(max_sum,curr_sum);
            if( curr_sum<0 ){
                curr_sum=0;
            }
        }
        return max_sum;
    }
}